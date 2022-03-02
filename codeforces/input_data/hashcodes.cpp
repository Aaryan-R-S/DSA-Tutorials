#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long int
#define vi vector
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define node pair<int,char>

#define loop(i,x,y) for(int i=x;i<y;i++)
#define deb(x) cout<< #x <<" "<<x<<endl;
#define print(x) cout<<x<<endl;
#define endl '\n' 

#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()

#define pi 3.14159265358979323846
const int MOD = 998244353 ;
const int N =  3e5+5 ;
const int INF = 1e18 ;

int len(string s){ int x = s.length(); return x;} 
 
/*-------------------------------------------------------------------------------------------------------------------------------*/
void test(int t){cin>>t;while(t--){}}
 
void read(vi<int>&v , int n){
	for(int i=0;i<n;i++){ cin>>v[i];}}

void read(int arr[],int n){
	for(int i=0;i<n;i++){ cin>>arr[i];}}
 
void write(vi<int>v ){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

void write(int arr[],int n){
	for(int i=0;i<n;i++){ cout<<arr[i]<<" "; }
	cout<<endl; 
}

void write(vi<pair<int,int>> v){
	for(int i=0;i<v.size();i++){ cout<<v[i].ff<<" "<<v[i].ss<<endl ; }
}

/*-------------------------------------------------------------------------------------------------*/

struct Skill {

	string course ;
	int level ;
};

struct Person {

	string name ;
	int avalilable = 0 ; 
	vector <Skill> skills ;
};

struct Project {

	string proj_name ;

	int duration ; 
	int score ;
	int deadline ;

	int roles ;

	vector<Skill> reqd_skills ;
};

/*---------------------------------------------------------------------------------------------------------------------------*/

// void printt ( vector<Project> projects){

// 	for(auto p : projects){

// 		cout << p.proj_name << " " <<  p.duration << " " << p.score << " " << p.deadline << endl ;

// 		for(auto s : p.reqd_skills ){

// 			cout << s.course <<" "<<s.level << endl ;
// 		}
// 	}
// }

// void printt( vector<Skill> persons){

// 	for(auto p : persons){

// 		cout << p.name << endl ;

// 		for(auto s : p.skills ){

// 			cout << s.course <<" "<<s.level << endl ;
// 		}
// 	}
// }

double rrr = 0.5 ; 

/*--------------------------------------------------------------------------------------------------------------------------- */

int32_t main(){

	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
 
	#ifndef ONLINE_JUDGE
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
			freopen("error.txt", "w", stderr);
	#endif

	int n , p ; 

	cin >> n >> p ;

	vector < Person > persons(n) ; 

	map < string, vector<Person> > m ;

	for(int i=0 ; i<n ; i++){

		int sz ;

		cin >> persons[i].name >> sz  ; 

		for(int j=1 ; j<=sz ; j++){

			string ss ; int lvl ; 

			cin >> ss >> lvl ;

			Skill curr_skill ;

			curr_skill.course = ss ; 
			curr_skill.level = lvl ;

			persons[i].skills.push_back(curr_skill) ; 
		}

		for(auto s : persons[i].skills){

			m[s.course].push_back(persons[i]) ;
		}
	}  

	vector<Project> projects(p) ;

	for(int i = 0 ; i< p ; i++){

		cin >> projects[i].proj_name >> projects[i].duration >> projects[i].score >> projects[i].deadline >> projects[i].roles ; 

		for(int j=1 ; j<=projects[i].roles ; j++){

			Skill ss ; 

			cin >> ss.course >> ss.level ; 

			projects[i].reqd_skills.push_back(ss) ;
		}
	} 

	// for(auto i : m){

	// 	cout << i.ff  << "-" << i.ss.size() << endl ; 
	// }

	// cout<<endl ;

	// vector < int > demand ( p ) ;

	map < string, int > proj_demand ;  

	for(auto p : projects){

		for(auto r : p.reqd_skills){

			for(auto x : m[r.course]){

				for(auto z : x.skills){

					if(z.course == r.course && z.level >= r.level ){

						proj_demand[p.proj_name] ++ ;  
					}
				}
			}
		}
	} 

	// for(auto i : proj_demand){

	// 	cout << i.ff  << "-" << i.ss << endl ; 
	// }

	sort(projects.begin(),projects.end() , [ & ] ( Project &a, Project &b){

		double p1 = ((1-rrr)*(double)a.score/a.deadline) - (rrr*(double)proj_demand[a.proj_name]) ;

		double p2 = ((1-rrr)*(double)b.score/b.deadline) - (rrr*(double)proj_demand[b.proj_name]) ;  

		return p1 > p2 ;
		  
	}) ;

	// for(auto p : projects){

	// 	cout << p.proj_name << endl;
	// }
    // cout<<"ook"<<endl;
    vector<vector<string>> ans; 
    for(int i=0; i<p; i++){
        vector<string> temp_2;
        bool poss = true;
        for(auto rskill: projects[i].reqd_skills){
            bool v = false;
            for(auto &pp: m[rskill.course]){
                int k = INT_MAX;
                for(int ii=0; ii<pp.skills.size(); ii++){
                    if(pp.skills[ii].course==rskill.course){
                        k = pp.skills[ii].level;
                    }
                }
                if(pp.avalilable<projects[i].deadline-projects[i].duration && rskill.level<=k){
                    // cout<<projects[i].proj_name<<" "<<pp.name<<endl;
                    // m[rskill.cour]
                    auto it = find(temp_2.begin(), temp_2.end(), pp.name);
                    if(it==temp_2.end()){
                        pp.avalilable = projects[i].deadline;
                        temp_2.push_back(pp.name);
                        v = true;
                        break;
                    }
                }
            }
            // if(v==false){
            //     cout<<projects[i].proj_name<<endl;
            // }
            poss &= v;
        }
        if(poss){
            vector<string> temp;
            temp.push_back(projects[i].proj_name);
            for(auto j: temp_2){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
    }

    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i][0]<<endl;
        for (int j = 1; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }        
        cout<<endl;
    }

}




