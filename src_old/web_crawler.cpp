// 1242. Web Crawler Multithreaded

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class HtmlParser 
{
public:
    vector<string> getUrls(string url) 
    {
        return vector<string>();
    }
};

class Solution 
{
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) 
    {
        auto host = hostName(startUrl);
        unordered_set<string> crawled;
        vector<thread*> threads;
        int tcnt = 0;
        urlq.push(startUrl);
        while (true)
        {
            while (!urlq.empty())
            {
                unique_lock<mutex> lck1(mtx);
                string url = urlq.front();
                urlq.pop();
                lck1.unlock();
                if (crawled.count(url) || hostName(url) != host) continue;
                crawled.insert(url);
                ++threadcnt;
                threads.push_back(new thread(&Solution::crawlUrl, this, url, &htmlParser));
            }
            unique_lock<mutex> lck2(mtx);
            cv.wait(lck2, [&](){ return urlq.size() || threadcnt <= 0; });
            if (urlq.empty() && threadcnt <= 0) break;
        }
        
        for (auto& th : threads) th->join();
        return vector<string>(crawled.begin(), crawled.end());
    }
    
private:
    void crawlUrl(string url, HtmlParser* parser)
    {
        vector<string> suburls = parser->getUrls(url);
        unique_lock<mutex> lck3(mtx);
        for (auto u : suburls) urlq.push(u);
        --threadcnt;
        cv.notify_all();
        lck3.unlock();
    }
    
    string hostName(const string& url)
    {
        auto pos1 = url.find("//");
        auto pos2 = url.find("/", pos1 + 2);
        if (pos2 == string::npos) pos2 = url.size();
        return url.substr(pos1 + 2, pos2 - (pos1 + 1) - 1);
    }
    
    mutex mtx;
    queue<string> urlq;
    int threadcnt = 0;
    condition_variable cv;
};

int main()
{
    return 0;
}