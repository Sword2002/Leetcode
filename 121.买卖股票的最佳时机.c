/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (53.93%)
 * Likes:    1236
 * Dislikes: 0
 * Total Accepted:    296.7K
 * Total Submissions: 539.4K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
 * 
 * 注意：你不能在买入股票前卖出股票。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [7,1,5,3,6,4]
 * 输出: 5
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 * ⁠    注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 * 
 * 
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){
    int i,j,profit=0,maxprices;
    for(i=0;i<pricesSize;i++)
    {
        maxprices=prices[i+1];
        for(j=pricesSize-1;j>i+1;j++)
        {
            maxprices>prices[j]?maxprices=maxprices:maxprices=prices[j];
        }
        profit > maxprices - prices[i] ? profit = profit : profit = maxprices-prices[i];
    }
    
    return profit;
}


// @lc code=end

