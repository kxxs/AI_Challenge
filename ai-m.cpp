#include<stdio.h>
#include "mydll.h"
#include "definition.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char Map[] = {
3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,1,1,1,1,3,3,3,3,3,3,3,3,3,3,
3,3,2,2,2,2,3,3,3,1,1,1,1,1,1,1,1,1,1,1,2,0,1,0,0,0,0,0,0,0,0,4,4,4,4,4,5,0,2,1,3,3,3,3,2,2,2,3,3,3,
3,3,2,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,0,1,4,4,4,4,4,4,4,4,4,6,6,6,4,5,0,2,1,3,3,3,2,3,3,3,3,3,3,
3,3,2,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,0,1,4,4,4,4,4,4,4,4,4,6,6,6,4,4,4,4,4,3,3,3,2,3,3,3,3,3,3,
3,3,2,2,2,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,2,2,0,5,4,6,6,6,4,1,1,2,4,3,3,3,2,3,3,3,3,3,3,
3,3,2,3,3,3,3,3,3,4,2,2,2,2,2,2,2,2,2,2,2,0,1,4,4,1,1,2,2,0,5,4,4,4,4,4,1,1,2,4,3,3,3,2,3,3,3,3,3,3,
3,3,2,3,3,3,3,3,3,4,2,2,2,2,2,2,2,2,2,2,2,0,1,4,4,1,1,2,2,0,0,5,5,4,4,1,1,1,2,4,3,3,3,3,2,2,2,3,3,3,
3,3,3,3,3,3,3,3,3,4,2,2,0,0,0,2,2,1,1,1,1,0,0,4,4,1,1,2,2,2,0,0,0,4,4,1,1,1,2,4,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,4,2,2,0,0,0,2,2,1,1,1,1,0,5,4,4,1,1,2,2,2,2,2,2,4,4,1,1,1,2,4,3,3,3,3,3,3,3,3,3,3,
1,1,1,4,4,4,4,4,4,4,2,2,2,2,2,2,2,1,1,1,1,3,4,4,4,4,4,1,2,2,2,2,2,4,4,1,1,1,2,4,4,4,4,4,4,4,1,1,1,1,
1,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,3,4,7,7,7,4,1,1,1,1,1,1,4,4,1,1,1,2,2,2,2,2,2,2,4,2,2,1,1,
1,0,0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,3,4,7,7,7,4,4,4,4,4,4,4,4,4,1,1,1,1,2,2,2,2,2,2,4,2,2,1,1,
1,5,5,4,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,3,4,7,7,7,4,4,4,4,4,4,4,4,4,2,2,2,1,2,2,0,0,2,2,4,2,2,1,1,
5,4,4,4,4,4,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,3,4,4,4,4,4,1,1,1,1,1,1,1,1,2,2,2,1,2,2,0,0,2,2,4,2,2,1,1,
5,4,8,8,8,4,4,4,4,4,4,4,4,1,3,2,2,3,3,3,3,3,0,4,4,1,1,3,3,3,3,3,3,3,3,2,2,2,1,2,2,0,0,2,2,4,2,2,1,1,
5,4,8,8,8,4,4,4,4,4,4,4,4,1,3,0,0,0,0,0,0,0,0,4,4,5,1,0,0,0,0,0,0,0,2,2,2,2,1,2,2,2,2,2,2,4,2,2,1,1,
1,4,8,8,8,4,5,0,2,2,1,4,4,1,3,0,1,1,1,1,1,1,1,4,4,1,1,1,1,1,1,1,1,0,2,2,2,2,1,2,2,2,2,2,2,4,2,2,1,1,
1,4,4,4,4,4,5,0,2,2,1,4,4,1,3,0,1,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,1,0,3,1,1,1,1,1,1,1,1,2,2,4,2,2,1,1,
1,0,4,4,5,5,0,0,2,2,1,4,4,1,3,0,1,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,1,0,3,1,1,1,1,1,1,1,1,2,2,4,2,2,1,1,
1,0,4,4,0,0,0,2,2,2,1,4,4,1,3,0,1,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,1,0,3,1,1,1,1,1,1,1,1,2,2,4,2,2,1,1,
1,0,4,4,2,2,2,2,2,2,1,4,4,1,3,0,1,3,3,3,2,1,1,1,1,1,1,1,2,3,3,3,1,0,3,1,1,1,5,1,1,1,1,2,2,4,2,2,1,1,
1,0,4,4,2,2,2,2,2,1,1,4,4,1,3,0,1,3,3,3,1,1,5,0,1,0,5,1,1,3,3,3,1,0,3,3,3,3,3,3,3,0,0,0,0,4,0,0,0,1,
1,0,4,4,1,1,1,1,1,4,4,4,4,4,1,1,1,3,3,3,1,5,4,4,4,4,4,5,1,3,3,3,1,0,0,0,4,4,4,4,4,5,0,1,1,4,1,1,1,1,
1,0,4,4,1,1,1,1,1,4,9,9,9,4,1,5,1,3,3,3,1,0,4,14,14,14,4,0,1,4,4,4,4,4,4,4,4,13,13,13,4,4,4,4,4,4,4,4,2,1,
1,0,4,4,4,4,4,4,4,4,9,9,9,4,4,4,4,4,4,4,1,1,4,14,14,14,4,1,1,4,4,4,4,4,4,4,4,13,13,13,4,4,4,4,4,4,4,4,2,1,
1,0,4,4,4,4,4,4,4,4,9,9,9,4,4,4,4,4,4,4,1,0,4,14,14,14,4,0,1,3,3,3,1,1,5,1,4,13,13,13,4,1,1,1,1,1,4,4,2,1,
1,1,1,1,4,1,1,0,5,4,4,4,4,4,0,0,1,3,3,3,1,5,4,4,4,4,4,5,1,3,3,3,1,1,1,1,4,4,4,4,4,1,1,1,1,1,4,4,2,1,
1,0,0,0,4,0,0,0,0,3,3,3,3,3,3,0,1,3,3,3,1,1,5,0,1,0,5,1,1,3,3,3,1,0,3,1,1,4,4,1,1,2,2,2,2,2,4,4,2,1,
2,2,2,2,4,2,2,1,1,1,1,5,1,1,3,0,1,3,3,3,2,1,1,1,1,1,1,1,2,3,3,3,1,0,3,1,1,4,4,1,2,2,2,2,2,2,4,4,2,1,
1,1,2,2,4,2,2,1,1,1,1,1,1,1,3,0,1,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,1,0,3,1,1,4,4,1,2,2,2,0,0,0,4,4,2,1,
1,1,2,2,4,2,2,1,1,1,1,1,1,1,3,0,1,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,1,0,3,1,1,4,4,1,2,2,0,0,5,5,4,4,2,1,
1,1,2,2,4,2,2,1,1,1,1,1,1,1,3,0,1,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,1,0,3,1,1,4,4,1,2,2,0,5,4,4,4,4,4,1,
1,1,2,2,4,2,2,2,2,2,2,1,2,2,2,0,1,1,1,1,1,1,1,1,4,4,1,1,1,1,1,1,1,0,3,1,1,4,4,1,2,2,0,5,4,12,12,12,4,1,
1,1,2,2,4,2,2,2,2,2,2,1,2,2,2,0,0,0,0,0,0,0,1,1,4,4,0,0,0,0,0,0,0,0,3,1,1,4,4,4,4,4,4,4,4,12,12,12,4,5,
1,1,2,2,4,2,2,0,0,2,2,1,2,2,3,3,3,3,3,3,3,3,1,5,4,4,0,3,3,3,3,3,2,2,3,1,1,4,4,4,4,4,4,4,4,12,12,12,4,5,
1,1,2,2,4,2,2,0,0,2,2,1,2,2,1,1,1,1,1,1,1,1,1,1,4,4,0,3,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,4,4,4,4,4,5,
1,1,2,2,4,2,2,0,0,2,2,1,2,2,1,1,1,1,1,1,1,1,4,4,4,4,4,3,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,4,5,5,1,
1,1,2,2,4,2,2,0,0,2,2,1,2,2,4,4,4,4,4,4,4,4,4,11,11,11,4,3,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,4,0,0,1,
1,1,2,2,4,2,2,2,2,2,2,1,1,1,4,4,4,4,4,4,4,4,4,11,11,11,4,3,5,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,4,2,2,1,
1,1,2,2,4,2,2,2,2,2,2,1,1,1,4,4,1,1,1,1,1,1,4,11,11,11,4,3,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,1,
1,1,1,1,4,4,4,4,4,4,2,1,1,1,4,4,2,2,2,2,2,1,4,4,4,4,4,3,1,1,1,1,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,1,1,1,
3,3,3,3,3,3,3,3,3,4,2,1,1,1,4,4,2,2,2,2,2,1,1,1,4,4,5,0,1,1,1,1,2,2,0,0,0,0,2,2,4,3,3,3,3,3,3,3,3,3,
3,3,3,3,2,3,3,3,3,4,2,1,1,1,4,4,0,0,0,2,2,2,1,1,4,4,0,0,1,1,1,1,2,2,0,0,0,0,2,2,4,3,3,3,3,2,2,3,3,3,
3,3,3,2,2,3,3,3,3,4,2,1,1,1,4,4,5,5,0,0,2,2,1,1,4,4,1,0,2,2,2,2,2,2,2,2,2,2,2,2,4,3,3,3,2,3,3,3,3,3,
3,3,3,3,2,3,3,3,3,4,2,1,1,4,4,4,4,4,5,0,2,2,1,1,4,4,1,0,2,2,2,2,2,2,2,2,2,2,2,2,4,3,3,3,2,3,3,3,3,3,
3,3,3,3,2,3,3,3,3,4,2,1,1,4,10,10,10,4,5,0,2,2,1,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,2,2,2,3,3,3,
3,3,3,3,2,3,3,3,3,4,4,4,4,4,10,10,10,4,4,4,4,4,4,4,4,4,1,0,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,2,3,3,2,3,3,
3,3,3,3,2,3,3,3,3,1,2,0,5,4,10,10,10,4,4,4,4,4,4,4,4,4,1,0,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,2,3,3,2,3,3,
3,3,3,2,2,2,3,3,3,1,2,0,5,4,4,4,4,4,0,0,0,0,0,0,0,0,1,0,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,2,2,3,3,3,
3,3,3,3,3,3,3,3,3,1,1,1,1,5,5,5,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3 };

//1:tree;3:water;4:path;6~14:tower;
/*
基本的四个添加指令的命令
info.myCommandList.addCommand(Produce,aim_tower_id,HeavyArcher);//造兵命令，第二个参数是造兵的塔id，第三个是造的兵种
info.myCommandList.addCommand(Attack,aim_soldier_id,x_position,y_position);//攻击命令，第二个参数是发起攻击的士兵id，第三和第四个参数是目标的x，y位置
info.myCommandList.addCommand(Upgrade,aim_tower_id);//升级命令，第二个参数是欲升级的塔id
info.myCommandList.addCommand(Move,aim_soldier_id,UP,distance);//移动命令，第二个参数是欲移动的士兵id，第三个参数是移动方向，第四个参数是移动距离
*/
#define inf 10000

bool user_pos[50][50];
int tower_blood[9];

char cmap(int x, int y) {
	return Map[x + (49 - y) * 50];
}

int dis(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int dis(const TPoint & p1, const TPoint & p2) {
	return dis(p1.x, p1.y, p2.x, p2.y);
}

int dis(const TPoint & p1, int x, int y) {
	return dis(p1.x, p1.y, x, y);
}

struct odisn {
	int prio, dis, x, y;
	odisn(int a, int b, int c, int d) :prio(a), dis(b), x(c), y(d) {}
};

bool operator<(odisn a, odisn b) {
	return a.prio > b.prio;
}
bool visited[50][50];
priority_queue <odisn> que;


class AI {
public:
	TSoldier self;
	enum MN { attack_tower, protect_tower, attack_enemy } mission;
	int enemy_lock = -1, tower_lock = -1, help_lock = -1, protect_lock = -1;
	TPoint target;
	int id;
	int need_help;
	//int last_x = -1;
	//int last_y = -1;
	bool alive = true;
	bool in_water = false;
	Info ifo;
	vector<AI>* ai;

	bool empty(int x, int y) {
		if (x >= 0 && x < 50 && y >= 0 && y < 50) {
			auto t = cmap(x, y);
			return ((in_water || t != 3) && t < 6) && !user_pos[x][y];//t != 3 &&
		} else {
			return false;
		}
	}
	int odis(int x1, int y1, int x2, int y2, int thres = 2) {
		if (dis(x1, y1, x2, y2) <= self.move_left) {
			return dis(x1, y1, x2, y2);
		}
		/*if (!empty(x1, y1)) {
			return dis(x1, y1, x2, y2);
		}*/
		if (cmap(x2, y2) == 3 || cmap(x1, y1) == 3) {
			in_water = true;
		} else {
			in_water = false;
		}
		int closest = inf;
		priority_queue <odisn> quee;
		que.swap(quee);
		que.push({ dis(x1,y1,x2,y2),0,x1,y1 });
		//printf("looking for (%d,%d) to (%d,%d)\n", x1, y1, x2, y2);
		memset(*visited, 0, 2500);
		visited[x1][y1] = true;
		while (!que.empty()) {
			auto p = que.top();
			que.pop();
			if (2 * p.prio < closest) {
				closest = 2 * p.prio;
			}
			if (p.prio <= thres) {
				//printf("answer is:%d\n", p.dis + t);
				return p.dis + p.prio;
			}
			if (!visited[p.x + 1][p.y] && empty(p.x + 1, p.y)) {
				visited[p.x + 1][p.y] = true;
				que.push({ dis(p.x + 1,p.y,x2,y2),p.dis + (cmap(p.x + 1,p.y) == 3 ? self.move_ability : 1),p.x + 1,p.y });
			}
			if (!visited[p.x - 1][p.y] && empty(p.x - 1, p.y)) {
				visited[p.x - 1][p.y] = true;
				que.push({ dis(p.x - 1,p.y,x2,y2),p.dis + (cmap(p.x - 1,p.y) == 3 ? self.move_ability : 1),p.x - 1,p.y });
			}
			if (!visited[p.x][p.y + 1] && empty(p.x, p.y + 1)) {
				visited[p.x][p.y + 1] = true;
				que.push({ dis(p.x ,p.y + 1,x2,y2),p.dis + (cmap(p.x,p.y + 1) == 3 ? self.move_ability : 1),p.x,p.y + 1 });
			}
			if (!visited[p.x][p.y - 1] && empty(p.x, p.y - 1)) {
				visited[p.x][p.y - 1] = true;
				que.push({ dis(p.x,p.y - 1,x2,y2),p.dis + (cmap(p.x,p.y - 1) == 3 ? self.move_ability : 1),p.x,p.y - 1 });
			}
		}
		return closest;
	}

	int odis(const TPoint & p1, const TPoint & p2, int thres = 2) {
		return odis(p1.x, p1.y, p2.x, p2.y, thres);
	}
	AI(int id_) {
		id = id_;
		need_help = 0;
		mission = attack_tower;
	}
	void set_ai(vector<AI> * ai_) {
		ai = ai_;
	}
	void update(Info & info) {
		alive = false;
		for (auto i : info.soldierInfo) {
			if (i.id == id) {
				self = i;
				alive = true;
				break;
			}
		}
		ifo = info;
		if (need_help > 0) {
			--need_help;
		}
	}
	void move(Info & info) {
		//TODO: add enemy attack 
		//if (info.playerInfo[info.myID].tower_num >= 2) {
		//	mission = protect_tower;
		//}
		//printf("%d,%d,%d\n", info.round, self.id, mission);
		int minhelpdis = inf;
		TPoint p;
		if (true) {//help_lock == -1
			for (auto b : *ai) {
				if (b.id != self.id && b.need_help > 0) {
					for (auto i : info.soldierInfo) {
						if (i.id == b.enemy_lock) {
							int d = dis(i.position, self.position);
							if (d / self.move_ability <= 5 && d < minhelpdis) {
								minhelpdis = d;
								p = i.position;
								help_lock = i.id;
							}
						}
					}
				}
			}
			if (minhelpdis != inf) {
				go(info, p);
				info.myCommandList.addCommand(Attack, self.id, p.x, p.y);
				return;
			}
		}
		if (info.playerInfo[info.myID].tower_num == 2 && info.round < 24) {
			mission = MN::protect_tower;
		}
		if (info.playerInfo[info.myID].tower_num == 2 && info.round == 25) {
			if (mission == MN::protect_tower) {
				mission = MN::attack_tower;
			}
		}
		if (mission == MN::attack_tower) {
			int d = inf, id = -1;
			TPoint tmp_target;
			for (auto i : info.towerInfo) {
				if (i.owner == info.myID) {
					if (i.id == tower_lock) {
						tower_lock = -1;
					}
					continue;
				}
				int tmp = dis(self.position, i.position);
				int soldier = 0;
				for (auto s : info.soldierInfo) {
					if (s.owner != info.myID && dis(s.position, i.position) < 8) {
						soldier += 1;
					}
				}
				//tmp += soldier+(i.level-1)*30;// remember to change the coeff.
				if (tmp < d) {
					d = tmp;
					id = i.id;
					tmp_target = i.position;
				}
			}
			if (id == -1) {
				//all tower acquired
				//printf("blank1");
			} else {
				if (tower_lock == -1) {
					tower_lock = id;
					target = tmp_target;
				}
			}
			/*if (info.myID == 1) {
				printf("soldier %d(%d,%d) go to tower %d(%d,%d) round %d\n", self.id, self.x_position, self.y_position, tower_lock, target.x, target.y,info.round);
			}*/
			//info.myCommandList.addCommand(Move, self.id, LEFT, 1);
			if (tower_lock == -1) {
				//change mission
				//printf("blank2");
			} else {
				int dx = 0, dy = 0;
				if (self.x_position > target.x) {
					dx = 1;
				}
				if (self.x_position < target.x) {
					dx = -1;
				}
				if (self.y_position > target.y) {
					dy = 1;
				}
				if (self.y_position < target.y) {
					dy = -1;
				}
				if (dis(self.position, target.x + dx, target.y + dy) <= self.range) {//arrived
					/*if (get_danger(self.x_position, self.y_position) > 3) {
						escape(info);
					}*/
					int danger = get_danger(self.x_position, self.y_position, true);
					if (danger > 0) {//run away now!
						auto list = get_enemy(info, self.x_position, self.y_position, self.move_left, true);
						if (list.size() == 0 || get_enemy(info, self.x_position, self.y_position).size() > 2) {
							list = get_enemy(info, self.x_position, self.y_position, 0, true);
							if (list.size() != 0) {
								int mindis = inf;
								auto e = list[0];
								for (auto r : list) {
									if (r.dis < mindis) {
										mindis = r.dis;
										e = r;
									}
								}
								enemy_lock = e.s.id;
								need_help = 3;
								//go(info, e.s.position);
								info.myCommandList.addCommand(Attack, self.id, e.s.x_position, e.s.y_position);
							}
							//printf("escape0\n");
							escape(info);
						} else {
							int mindis = inf;
							auto e = list[0];
							for (auto r : list) {
								if (r.dis < mindis) {
									mindis = r.dis;
									e = r;
								}
							}
							enemy_lock = e.s.id;
							need_help = 3;
							go(info, e.s.position);//TODO tai mao jin
							info.myCommandList.addCommand(Attack, self.id, e.s.x_position, e.s.y_position);
							//printf("escape1\n");
							escape(info, 2);
						}
					}/* else {
						need_help = 0;
					}*/
					info.myCommandList.addCommand(Attack, self.id, target.x + dx, target.y + dy);
					//last_x = last_y = -1;
				} else {
					int mx = self.x_position, my = self.y_position;
					//if (last_x == mx && last_y == my) {//something's gone wrong with last 'go'
					//	printf("blocked at (%d,%d)", mx, my);
					//	if (empty(mx + 1, my)) {
					//		info.myCommandList.addCommand(Move, self.id, RIGHT, 1);
					//	} else if (empty(mx - 1, my)) {
					//		info.myCommandList.addCommand(Move, self.id, LEFT, 1);
					//	} else if (empty(mx, my + 1)) {
					//		info.myCommandList.addCommand(Move, self.id, UP, 1);
					//	} else if (empty(mx, my - 1)) {
					//		info.myCommandList.addCommand(Move, self.id, DOWN, 1);
					//	}
					//}
					//last_x = mx;
					//last_y = my;
					auto list = get_enemy(info, mx, my, 0, true);//TODO possible bug
					if (list.size() != 0) {
						int mind = list[0].danger;
						auto e = list[0];
						for (auto i : list) {
							if (i.danger < mind) {
								e = i;
							}
						}
						mission = MN::attack_enemy;
						enemy_lock = list[0].s.id;
						need_help = 5;
						info.myCommandList.addCommand(Attack, self.id, list[0].s.x_position, list[0].s.y_position);
						return move(info);
					}
					go(info, target.x + dx, target.y + dy);
					info.myCommandList.addCommand(Attack, self.id, target.x + dx, target.y + dy);
				}
			}
		} else if (mission == MN::attack_enemy) {
			//printf("enemy locked, %d attack %d\n", self.id, enemy_lock);
			auto ene = get_enemy(info, self.x_position, self.y_position);
			if (ene.size() > 2) {
				//printf("escape2\n");
				escape(info);
			}
			auto e = self;
			bool found = false;
			for (auto i : info.soldierInfo) {
				if (i.id == enemy_lock) {
					e = i;
					found = true;
					break;
				}
			}
			if (!found) {
				mission = attack_tower;
				enemy_lock = -1;
				return move(info);
			}
			if (dis(e.position, self.position) <= self.range) {
				info.myCommandList.addCommand(Attack, self.id, e.x_position, e.y_position);
				/*if (tower_lock != -1) {
					mission = attack_tower;
				}*/
				if (get_enemy(info, self.x_position, self.y_position).size() > 1) {//run after attack
					escape(info);
				}
			} else {
				if (e.move_left > self.move_left) {
					mission = attack_tower;
					need_help = 0;
				} else {
					go(info, e.position);
					info.myCommandList.addCommand(Attack, self.id, e.x_position, e.y_position);
					escape(info);
				}
			}
		} else if (mission == MN::protect_tower) {
			vector<TowerInfo> towers;
			for (auto i : info.towerInfo) {
				if (i.owner == info.myID) {
					towers.push_back(i);
				}
			}
			if (towers.size() == 0 && tower_lock != -1) {
				mission = attack_tower;
				return move(info);
			}
			TowerInfo pt = towers[0];
			int pt_enemies = 0;
			if (protect_lock == -1) {
				int mindis = inf;
				for (auto i : towers) {
					int d = dis(self.position, i.position);
					int enemies = 0;
					for (auto e : info.soldierInfo) {
						if (dis(i.position, e.position) < 7) {
							if (e.owner == info.myID) {
								for (auto& a : *ai) {
									if (a.self.id == e.id) {
										if (a.mission == protect_tower && a.protect_lock == i.id) {
											enemies -= 1;
										}
										break;
									}
								}
							} else {
								enemies += 2;
							}
						}
					}
					if (i.blood < tower_blood[i.id]) {
						enemies += (tower_blood[i.id] - i.blood + 39) / 40 + 1;
					}
					d -= enemies * 3;//TODO change coeff.
					if (d < mindis) {
						pt = i;
						mindis = d;
						pt_enemies = enemies;
					}
				}
				protect_lock = pt.id;
			} else {
				for (auto i : info.towerInfo) {
					if (i.id == protect_lock) {
						pt = i;
					}
				}
			}
			if (pt.owner != info.myID) {//tower is already taken away
				int dx = 0, dy = 0;
				auto target = pt.position;
				if (self.x_position > target.x) {
					dx = 1;
				}
				if (self.x_position < target.x) {
					dx = -1;
				}
				if (self.y_position > target.y) {
					dy = 1;
				}
				if (self.y_position < target.y) {
					dy = -1;
				}
				if (dis(self.position, target.x + dx, target.y + dy) <= self.range) {
					info.myCommandList.addCommand(Attack, self.id, target.x + dx, target.y + dy);
				} else {
					go(info, target.x + dx, target.y + dy);
				}
			} else {
				int mindis = inf;
				auto en = self;
				for (auto e : info.soldierInfo) {
					if (e.owner == info.myID) {
						continue;
					}
					if (dis(e.position, pt.position) < 10) {
						int d = dis(e.position, pt.position);
						if (d<mindis && self.attack>e.armor) {
							mindis = d;
							en = e;
						}
					}
				}
				if (mindis != inf) {
					go(info, en.position);
					info.myCommandList.addCommand(Attack, self.id, en.x_position, en.y_position);
				} else {
					if (pt_enemies <= -2) {//at least two defenders
						mission = attack_tower;
						protect_lock = -1;
						return move(info);
					} else {
						/*int mindis=inf;
						TPoint target;
						for (auto i : info.soldierInfo) {
							if (i.owner == info.myID&&i.id!=self.id) {
								if (dis(self.position, i.position) < mindis) {
									target = i.position;
								}
							}
						}
						printf("akjshlassjda\n");*/
						if (info.round > 24) {
							go(info, pt.position);
						}
					}
				}
			}
		}
	}
	void go(Info & info, int x, int y, int step = -1) {
		int dx = 0, dy = 0, mx = self.x_position, my = self.y_position;
		if (step == -1) {
			step = self.move_left;
		}
		struct tmp {
			int dis, dx, dy;
		};
		user_pos[mx][my] = 0;
		for (int i = 0; i <= step; ++i) {
			if (step <= 0) {
				break;
			}
			int mindis = inf;
			int tdis;
			dx = dy = 0;
			for (int k = 1; k <= step; ++k) {
				if (empty(mx + k, my)) {
					if ((tdis = ddis(mx + k, my, x, y)) < mindis) {
						dx = k;
						dy = 0;
						mindis = tdis;
					}
				}
				if (empty(mx - k, my)) {
					if ((tdis = ddis(mx - k, my, x, y)) < mindis) {
						dx = -k;
						dy = 0;
						mindis = tdis;
					}
				}
				if (empty(mx, my + k)) {
					if ((tdis = ddis(mx, my + k, x, y)) < mindis) {
						dx = 0;
						dy = k;
						mindis = tdis;
					}
				}
				if (empty(mx, my - k)) {
					if ((tdis = ddis(mx, my - k, x, y)) < mindis) {
						dx = 0;
						dy = -k;
						mindis = tdis;
					}
				}
			}
			/*if (step >= 2 && empty(mx + 2, my)) {
				if ((tdis = ddis(mx + 2, my, x, y)) < mindis) {
					dx = 2;
					dy = 0;
					mindis = tdis;
				}
			}
			if (step >= 2 && empty(mx - 2, my)) {
				if ((tdis = ddis(mx - 2, my, x, y)) < mindis) {
					dx = -2;
					dy = 0;
					mindis = tdis;
				}
			}
			if (step >= 2 && empty(mx, my + 2)) {
				if ((tdis = ddis(mx, my + 2, x, y)) < mindis) {
					dx = 0;
					dy = 2;
					mindis = tdis;
				}
			}
			if (step >= 2 && empty(mx, my - 2)) {
				if ((tdis = ddis(mx, my - 2, x, y)) < mindis) {
					dx = 0;
					dy = -2;
					mindis = tdis;
				}
			}*/
			if (mindis < ddis(mx, my, x, y)) {
				mx += dx;
				my += dy;
				step -= abs(dx) + abs(dy);
				if (dx > 0) {
					info.myCommandList.addCommand(Move, self.id, RIGHT, dx);
				}
				if (dx < 0) {
					info.myCommandList.addCommand(Move, self.id, LEFT, -dx);
				}
				if (dy > 0) {
					info.myCommandList.addCommand(Move, self.id, UP, dy);
				}
				if (dy < 0) {
					info.myCommandList.addCommand(Move, self.id, DOWN, -dy);
				}
			}
			if (mission != attack_enemy) {//TODO
				auto list = get_enemy(info, mx, my);
				if (list.size() != 0) {
					enemy l_e;
					int least_danger = inf;
					for (auto e : list) {
						if (e.attackable && e.danger < least_danger) {
							least_danger = e.danger;
							l_e = e;
						}
					}
					if (least_danger != inf) {
						info.myCommandList.addCommand(Attack, self.id, l_e.s.x_position, l_e.s.y_position);
					}
				}
			}
			//printf("(%d,%d) to (%d,%d) = (%d,%d)\n", mx, my, x, y, dx, dy);
		}
		/*if (step == self.move_left) {
			if (empty(mx + 1, my)) {
				mx += 1;
				info.myCommandList.addCommand(Move, self.id, RIGHT, 1);
			} else if (empty(mx - 1, my)) {
				mx -= 1;
				info.myCommandList.addCommand(Move, self.id, LEFT, 1);
			} else if (empty(mx, my + 1)) {
				my += 1;
				info.myCommandList.addCommand(Move, self.id, UP, 1);
			} else if (empty(mx, my - 1)) {
				my -= 1;
				info.myCommandList.addCommand(Move, self.id, DOWN, 1);
			}
		}*/
		user_pos[mx][my] = 1;
	}
	void go(Info & info, const TPoint & p, int step = -1) {
		go(info, p.x, p.y, step);
	}
	void escape(Info & info, int step = -1) {
		int dx = 0, dy = 0, mx = self.x_position, my = self.y_position;
		if (step == -1) {
			step = self.move_left;
		}
		struct tmp {
			int dis, dx, dy;
		};
		user_pos[mx][my] = 0;
		for (int i = 0; i < step; ++i) {
			if (step <= 0) {
				break;
			}
			dx = dy = 0;
			int mindis = inf;
			int tdis;
			for (int k = 1; k <= step; ++k) {
				if (empty(mx + k, my)) {
					if ((tdis = get_d(mx + k, my, true)) < mindis) {
						dx = k;
						dy = 0;
						mindis = tdis;
					}
				}
				if (empty(mx - k, my)) {
					if ((tdis = get_d(mx - k, my, true)) < mindis) {
						dx = -k;
						dy = 0;
						mindis = tdis;
					}
				}
				if (empty(mx, my + k)) {
					if ((tdis = get_d(mx, my + k, true)) < mindis) {
						dx = 0;
						dy = k;
						mindis = tdis;
					}
				}
				if (empty(mx, my - k)) {
					if ((tdis = get_d(mx, my - k, true)) < mindis) {
						dx = 0;
						dy = -k;
						mindis = tdis;
					}
				}
			}
			/*if (step >= 2 && empty(mx + 2, my)) {
				if ((tdis = get_d(mx + 2, my, true)) < mindis) {
					dx = 2;
					dy = 0;
					mindis = tdis;
				}
			}
			if (step >= 2 && empty(mx - 2, my)) {
				if ((tdis = get_d(mx - 2, my, true)) < mindis) {
					dx = -2;
					dy = 0;
					mindis = tdis;
				}
			}
			if (step >= 2 && empty(mx, my + 2)) {
				if ((tdis = get_d(mx, my + 2, true)) < mindis) {
					dx = 0;
					dy = 2;
					mindis = tdis;
				}
			}
			if (step >= 2 && empty(mx, my - 2)) {
				if ((tdis = get_d(mx, my - 2, true)) < mindis) {
					dx = 0;
					dy = -2;
					mindis = tdis;
				}
			}*/
			if (mindis <= get_d(mx, my, true)) {
				mx += dx;
				my += dy;
				step -= abs(dx) + abs(dy);
				if (dx > 0) {
					info.myCommandList.addCommand(Move, self.id, RIGHT, dx);
				}
				if (dx < 0) {
					info.myCommandList.addCommand(Move, self.id, LEFT, -dx);
				}
				if (dy > 0) {
					info.myCommandList.addCommand(Move, self.id, UP, dy);
				}
				if (dy < 0) {
					info.myCommandList.addCommand(Move, self.id, DOWN, -dy);
				}
			}
			auto list = get_enemy(info, mx, my, true);
			if (list.size() != 0) {
				enemy l_e;
				int least_danger = inf;
				for (auto e : list) {
					if (e.danger < least_danger) {
						least_danger = e.danger;
						l_e = e;
					}
				}
				if (least_danger != inf) {
					info.myCommandList.addCommand(Attack, self.id, l_e.s.x_position, l_e.s.y_position);
				}
			}
			//printf("(%d,%d) to (%d,%d) = (%d,%d)\n", mx, my, x, y, dx, dy);
		}
		if (step == self.move_left) {
			if (empty(mx + 1, my)) {
				mx += 1;
				info.myCommandList.addCommand(Move, self.id, RIGHT, 1);
			} else if (empty(mx - 1, my)) {
				mx -= 1;
				info.myCommandList.addCommand(Move, self.id, LEFT, 1);
			} else if (empty(mx, my + 1)) {
				my += 1;
				info.myCommandList.addCommand(Move, self.id, UP, 1);
			} else if (empty(mx, my - 1)) {
				my -= 1;
				info.myCommandList.addCommand(Move, self.id, DOWN, 1);
			}
		}
		user_pos[mx][my] = 1;
	}
	struct enemy {
		TSoldier s;
		int danger = 0, attack_s = inf, attack_me = inf, dis, harm_s = 0, harm_me = 0;
		bool attackable = false;
	};

	vector<enemy> get_enemy(Info & info, int x, int y, int move = 0, bool attackable_only = false) {
		vector<enemy> list;
		for (auto s : info.soldierInfo) {
			if (s.owner != info.myID) {
				enemy e;
				e.s = s;
				e.dis = dis(s.position, x, y);
				bool in_range = false;
				if (e.dis <= s.move_left + s.range) {
					in_range = true;
					e.harm_s = s.attack - self.armor;
					if (e.harm_s <= 0) {
						e.attack_s = inf;
					} else {
						e.attack_s = self.blood / e.harm_s + ((self.blood % e.harm_s == 0) ? 0 : 1);
					}
				}
				if (e.dis <= self.range + move) {//no [self.move_left +] for now
					in_range = true;
					e.attackable = true;
					e.harm_me = self.attack - s.armor;
					if (e.harm_me <= 0) {
						e.attackable = false;
						e.attack_me = inf;
					} else {
						e.attack_me = s.blood / e.harm_me + ((s.blood % e.harm_me == 0) ? 0 : 1);
					}
				}
				e.danger = (e.attack_s == inf ? 0 : 20-e.attack_s);// (e.attack_me == inf ? 20 : e.attack_me);
				if (in_range && (!attackable_only || e.attackable)) {
					list.push_back(e);
				}
				/*if (info.myID == 1 && e.danger != 0) {
					printf("(%d,%d)-danger:%d,%d\n", x,y, e.s.id,e.danger);
				}*/
			}
		}
		return list;
	}
	int get_danger(Info & info, int x, int y, bool pos_only = false) {
		auto list = get_enemy(info, x, y);
		if (list.size() == 0) {
			return 0;
		} else {
			int d = 0;
			for (auto i : list) {
				if (!pos_only || i.danger > 0) {
					d += i.danger;
				}
			}
			return d;
		}
	}
	int get_d(int x, int y, bool no) {
		auto list = get_enemy(ifo, x, y);
		int d = 0;
		for (auto e : list) {
			d -= e.dis;
		}
	}
	int get_danger(int x, int y, bool pos_only = false) {
		return get_danger(ifo, x, y, pos_only);
	}
	int ddis(int x1, int y1, int x2, int y2) {
		/*int d = get_danger(ifo, x1, y1);
		d = d < 0 ? -1 : d;
		int t = odis(x1, y1, x2, y2);
		return t<10?t:t+d;*/
		return odis(x1, y1, x2, y2);
	}
};

vector<AI> ai;
bool soldiers[1000];
bool first_run = true;

void player_ai(Info & info)
{
	static TSoldierType slist[] = { HeavyInfantry,HeavyArcher,LightKnight,HeavyInfantry,HeavyArcher,HeavyArcher,HeavyArcher,HeavyKnight };
	int N = 0;
	static int pointer = 0;
	if (first_run) {
		memset(soldiers, 0, 1000);
		for (auto i : info.towerInfo) {
			tower_blood[i.id] = i.blood;
		}
		first_run = false;
		//printf("123");
	}
	vector<TowerInfo> towers;
	for (auto i : info.towerInfo) {
		if (i.owner == info.myID && !i.recruiting) {
			if (i.blood > 40) towers.push_back(i);
		}
	}
	memset(*user_pos, 0, 2500);
	for (auto i : info.soldierInfo) {
		user_pos[i.x_position][i.y_position] = 1;
		if (i.owner == info.myID && !soldiers[i.id]) {
			//printf("add %d(%d,%d)\n", i.id,i.x_position,i.y_position);
			++pointer;
			ai.push_back({ i.id });
			soldiers[i.id] = true;
		}
	}
	sort(towers.begin(), towers.end(), [](TowerInfo & a, TowerInfo & b) {return a.blood > b.blood; });
	for (auto i : towers) {
		/*switch (info.myID) {
			case 0:
				info.myCommandList.addCommand(Produce, i, HeavyArcher);
				break;
			case 1:
				info.myCommandList.addCommand(Produce, i, HeavyInfantry);
				break;
			case 2:
				info.myCommandList.addCommand(Produce, i, HeavyKnight);
				break;
			default:
				info.myCommandList.addCommand(Produce, i, LightKnight);
				break;
			}*/
		if (pointer < N) {
			info.myCommandList.addCommand(Produce, i.id, slist[pointer]);
		} else {
			//if (pointer % 3 == 0) {
			//	info.myCommandList.addCommand(Produce, i.id, HeavyInfantry);
			//} else {
			info.myCommandList.addCommand(Produce, i.id, HeavyArcher);
			//}
		}
	}
	for (AI& i : ai) {
		if (i.alive) {
			i.update(info);
		}
		if (i.alive) {
			i.set_ai(&ai);
			i.move(info);
		}
	}
	for (auto i : info.towerInfo) {
		tower_blood[i.id] = i.blood;
	}
}