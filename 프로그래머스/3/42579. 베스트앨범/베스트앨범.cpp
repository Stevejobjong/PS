#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<string, int>& a, pair<string, int>& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}
class Song {
public:
	string genre;
	int play;
	int idx;
	Song() {}
	Song(string _genre, int _play, int _idx){
		genre = _genre;
		play = _play;
		idx = _idx;
	}
	bool operator<(const Song& song) {
		return this->play < song.play;
	}
};
bool cmpSong(Song& a, Song& b) {
	return a.play > b.play;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
	vector<Song> songVec;
	for (int i = 0; i < genres.size(); i++) {
		songVec.push_back(Song(genres[i], plays[i], i));
	}
	map<string, int> m;
	for (int i = 0; i < genres.size(); i++) {
		if (m.find(genres[i]) != m.end()) {
			m[genres[i]] = m[genres[i]] + plays[i];
		}
		else
			m[genres[i]] = plays[i];
	}
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	sort(songVec.begin(), songVec.end(), cmpSong);

	for (int i = 0; i < v.size(); i++) {
		int cnt = 2;
		for (int j = 0; j < songVec.size(); j++) {
			if (songVec[j].genre == v[i].first) {
				cnt--;
				answer.push_back(songVec[j].idx);
			}
			if (cnt == 0)
				break;
		}
	}
    return answer;
}