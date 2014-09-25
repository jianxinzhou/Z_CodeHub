统计词频问题，采用了停用词，以及按照词频排序输出（以圣经为例）。 

以下比较了三种数据结构分别在添加dict与排序方面消耗的时间。

时间复杂度指添加dict的复杂度。

a)	vector<pair<string, int> >  vector<string> ： 30403ms 7ms              时间复杂度 n方

b)	map<string, int> set<string> ：1221ms  10ms                            时间复杂度 nlogn

c)	unordered_map<string, int> unordered_set<string> ： 598ms 9ms          时间复杂度 常量
