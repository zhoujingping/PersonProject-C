#include "stdafx.h"
#include "core.h"

void add(string &s, unordered_map<string, int> &Map) { Map[s]++; s = ""; }

bool checkword(char ch) { return ch >= 'a' && ch <= 'z'; }

bool checknumber(char ch) { return ch >= '0' && ch <= '9'; }

int CountChar(char *name) {
	int ch;
	FILE *stream;
	freopen_s(&stream, name, "r", stdin);
	int characters = 0, now = -1;
	while (ch = getchar()) {
		if (ch == -1) break;
		if (ch > 128) continue;
		characters++;
	}
	if (characters == 0) { cout << "File not found!"; }
	return characters;
}

pii CountWord(char *name) {
	int ch;
	FILE *stream;
	freopen_s(&stream, name, "r", stdin);
	int words = 0, line = 0, now = -1;
	while (ch = getchar()) {
		if (ch == -1) { if (now >= 4) words++; break; }
		if (ch > 128) continue;
		if (ch == '\n') { if (now >= 4) words++; now = -1; continue; }
		if (ch >= 'A' && ch <= 'Z') ch -= 'A' - 'a';
		if (now == -2) { if (!checkword(ch) && !checknumber(ch)) now = 0; continue; }
		if (checkword(ch)) { if (now == -1) now = 1, line++; else now++; continue; }
		if (checknumber(ch)) {
			if (now == -1) now = -2, line++;
			else if (now >= 4) now++;
			else now = -2;
			continue;
		}
		if (now == -1) { if (ch != ' ') now = 0, line++; continue; }
		if (now >= 4) words++; now = 0;
	}
	return mp(words, line);
}

vector<pair<string, int> > CountFrequentWord(char *name) {
	FILE *stream;
	string s;
	unordered_map<string, int> Map;
	freopen_s(&stream, name, "r", stdin);
	int now = -1, ch;
	while (ch = getchar()) {
		if (ch == -1) { if (now >= 4) add(s, Map); break; }
		if (ch > 128) continue;
		if (ch == '\n') { if (now >= 4) add(s, Map); s = ""; now = -1; continue; }
		if (ch >= 'A' && ch <= 'Z') ch -= 'A' - 'a';
		if (now == -2) { if (!checkword(ch) && !checknumber(ch)) now = 0; continue; }
		if (checkword(ch)) { if (now == -1) now = 1; else now++; s += ch; continue; }
		if (checknumber(ch)) {
			if (now == -1) now = -2;
			else if (now >= 4) now++, s += ch;
			else now = -2, s = "";
			continue;
		}
		if (now >= 4) add(s, Map); s = ""; now = 0;
	}
	vector<pair<string, int> > tmp;
	vi tmp2;
	for (auto u : Map) tmp2.pb(u.se);
	int n = sz(tmp2), x;
	if (sz(tmp2) >= 10) {
		nth_element(tmp2.begin(), tmp2.begin() + 10, tmp2.end(), [&](int a, int b) {return a > b; });
		n = 10;
	}
	else sort(all(tmp2), [&](int a, int b) {return a > b; });
	x = tmp2[n - 1];
	for (auto u : Map) if (u.se >= x) tmp.pb(u);
	n = sz(tmp);
	if (sz(tmp) >= 10) {
		nth_element(tmp.begin(),tmp.begin() + 10, tmp.end(), [&](pair<string, int> a, pair<string, int> b) {if (a.se != b.se) return a.se > b.se; return a.fi < b.fi; });
		n = 10;
	}
	sort(tmp.begin(), tmp.begin() + n, [&](pair<string, int> a, pair<string, int> b) {if (a.se != b.se) return a.se > b.se; return a.fi < b.fi; });
	//sort(tmp.begin(), tmp.end(), [&](pair<string, int> a, pair<string, int> b) {if (a.se != b.se) return a.se > b.se; return a.fi < b.fi; });
	return tmp;
}
