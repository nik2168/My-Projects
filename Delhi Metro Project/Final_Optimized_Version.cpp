#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<string>
#include<unordered_map>
#include<map>
#include<stack>
#include<unordered_set>
#include<climits>
using namespace std;

class line{
public:
vector<string> stations;
string name;
double distance;
double time;
int interchanges;
};

class station_info{
public:
string name;
double distance;
double time;
int interchanges;
int dest;
string linename;
};

class metro{
    public:
    vector<line> m;
    metro(){

    }
    void insert(line x){
        m.push_back(x);
    }

    int size(){
     return m.size();
    }

    line line_details(int i){
       return m[i];
    }

    void print(){
        for( auto x : m ){
            cout<<"Name : "<<x.name<<endl;
            vector<string> s = x.stations;
            for(int i = 0; i < s.size(); i++){
                cout<<s[i]<<" ";
            }
            cout<<endl;
            cout<<"Distance : "<<x.distance<<endl;
            cout<<"Time : "<<x.time<<endl;
            cout<<"Interchange : "<<x.interchanges<<endl;
        }
    }
};

string make_uppercase(string & s){
    for(int i = 0; i < s.size(); i++){
    if(s[i] > 96 && s[i] < 123){
        s[i] -= 32;
    }
}
return s;
}

vector<list<station_info>>graph;
int total_distance = 0;
int total_time = 0;
unordered_map<string, station_info> stationsmap;
vector<station_info> allstations;
void get_edges(station_info i, station_info j){
    graph[i.dest].push_back(j);
    graph[j.dest].push_back(i);
}

void display(){
for(int x = 0; x < graph.size(); x++){
    cout<<x<<" -> ";
    for(auto y : graph[x]){
        cout<<"( "<<y.distance<<" , "<<y.time<<" , "<<y.dest<<" )";
    }
    cout<<endl;
}
}

stack<station_info> finder(station_info &src, station_info &dst){
        unordered_map<int, station_info> mp; // will store src & dist
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q; // will store dist & destination
        unordered_set<int> vis; // visited nodes
        vector<station_info> par(300); // parent node;
        for(int i = 0; i < 300; i++){
            station_info t;
            t.distance = INT_MAX;
                mp[i] = t;
        }
        src.distance = 0;
        q.push(make_pair(0, src.dest));
        mp[src.dest] = src;
        par[src.dest] = src;
        while(!q.empty()){
                pair<double,int> cur = q.top();
                q.pop();
                if(vis.count(cur.second) == 1) continue;
                vis.insert(cur.second);
                for(auto x : graph[cur.second]){
                        double td = cur.first + x.distance;
                 if(mp[x.dest].distance > td){
                        mp[x.dest].distance = td;
                        q.push(make_pair(td, x.dest));
                        par[x.dest] = allstations[cur.second];
                                }
                        }
        }
        total_distance = mp[dst.dest].distance;
        stack<station_info> s;
        station_info path;
        path = dst;
        s.push(dst);
        total_time += path.time;
        while(path.dest != src.dest){
            s.push(par[path.dest]);
           total_time += s.top().time;
           path = par[path.dest];
        }
        s.push(src);
        return s;
}



int main(){

    metro m;

    line blueline;
    blueline.stations = {"DWARKA SECTOR-21",
    "DWARKA SECTOR-8","DWARKA SECTOR-9","DWARKA SECTOR-10",
    "DWARKA SECTOR-11","DWARKA SECTOR-12","DWARKA SECTOR-13",
    "DWARKA SECTOR-14","DWARKA","DWARKA MOR","NAWADA",
    "UTTAM NAGAR WEST","UTTAM NAGAR EAST","JANAKPURI WEST",
    "JANAKPURI EAST","TILAK NAGAR","SUBHASH NAGAR","TAGORE GARDEN",
    "RAJOURI GARDEN","RAMESH NAGAR","MOTI NAGAR","KIRTI NAGAR",
    "SHADIPUR","PATEL NAGAR","RAJENDRA PLACE","KAROL BAGH",
    "JHANDEWALAN","RAMAKRISHNA ASHRAM MARG","RAJIV CHOWK",
    "BARAKHAMBA ROAD","MANDI HOUSE","SUPREME COURT","INDRAPRASTHA",
    "YAMUNA BANK","AKSHARDHAM","MAYUR VIHAR -I","MAYUR VIHAR EXTENSION",
    "NEW ASHOK NAGAR","NOIDA SECTOR-15","NOIDA SECTOR-16",
    "NOIDA SECTOR-18","BOTANICAL GARDEN","GOLF COURSE",
    "NOIDA CITY CENTRE","SECTOR-34 NOIDA","SECTOR-52 NOIDA",
    "SECTOR-61 NOIDA","SECTOR-59 NOIDA","SECTOR-62 NOIDA",
    "NOIDA ELECTRONIC CITY"};
     blueline.distance = 1.11;
     blueline.time = 1.7;
     blueline.interchanges = 10;
     blueline.name = "blueline";
     m.insert(blueline);

     line redline;
     redline.stations = {
    "SHAHEED STHAL(NEW BUS ADDA)","HINDON RIVER","ARTHALA","MOHAN NAGAR","SHYAM PARK",
    "MAJOR MOHIT SHARMA RAJENDRA NAGAR","RAJ BAGH","SHAHEED NAGAR","DILSHAD GARDEN",
    "JHILMIL","MANSAROVAR PARK","SHAHDARA","WELCOME","SEELAMPUR","SHASTRI PARK",
    "KASHMERE GATE","TIS HAZARI","PULBANGASH","PRATAP NAGAR","SHASTRI NAGAR",
    "INDERLOK","KANHAIYA NAGAR","KESHAV PURAM","NETAJI SUBHASH PLACE","KOHAT ENCLAVE",
    "PITAMPURA","ROHINI EAST","ROHINI WEST","RITHALA"    
    };
     redline.distance = 1.15;
     redline.time = 1.6;
     redline.interchanges = 4;
     redline.name = "redline";
     m.insert(redline);

     line magentaline;
     magentaline.stations = {
    "JANAKPURI WEST","DABRI MOR-JANAKPURI SOUTH","DASHRATHPURI","PALAM","SADAR BAZAR CANTONMENT",
    "TERMINAL 1-IGI AIRPORT","SHANKAR VIHAR","VASANT VIHAR","MUNIRKA","R.K.PURAM",
    "IIT","HAUZ KHAS","PANCHSHEEL PARK","CHIRAG DELHI","GREATER KAILASH","NEHRU ENCLAVE",
    "KALKAJI MANDIR","OKHLA NSIC","SUKHDEV VIHAR","JAMIA MILLIA ISLAMIA","OKHLA VIHAR",
    "JASOLA VIHAR SHAHEEN BAGH","KALINDI KUNJ","OKHLA BIRD SANCTUARY","BOTANICAL GARDEN"
    };
    magentaline.distance = 1.36;
    magentaline.time = 2.4;
    magentaline.interchanges = 4;
    magentaline.name = "magentaline";
    m.insert(magentaline);

    line violetline;
    violetline.stations = {
    "KASHMERE GATE","LAL QUILA","JAMA MASJID","DELHI GATE","ITO","MANDI HOUSE","JANPATH",
    "CENTRAL SECRETARIAT","KHAN MARKET","JLN STADIUM","JANGPURA","LAJPAT NAGAR","MOOLCHAND",
    "KAILASH COLONY","NEHRU PLACE","KALKAJI MANDIR","GOVIND PURI","HARKESH NAGAR OKHLA",
    "JASOLA-APOLLO","SARITA VIHAR","MOHAN ESTATE","TUGHLAKABAD STATION","BADARPUR BORDER",
    "SARAI","NHPC CHOWK","MEWALA MAHARAJPUR","SECTOR-28","BADKAL MOR","OLD FARIDABAD",
    "NEELAM CHOWK AJRONDA","BATA CHOWK","ESCORTS MUJESAR","SANT SURDAS (SIHI)","RAJA NAHAR SINGH (BALLABHGARH)"
    };
    violetline.distance = 1.32;
    violetline.time = 1.88;
    violetline.interchanges = 5;
    violetline.name = "violetline";
    m.insert(violetline);

    line yellowline;
    yellowline.stations = {
    "SAMAYPUR BADLI","ROHINI SECTOR-18,19","HAIDERPUR BADLI MOR","JAHANGIRPURI",
"ADARSH NAGAR","AZADPUR","MODEL TOWN","GURU TEG BAHADUR NAGAR",
"VISHWAVIDYALAYA","VIDHAN SABHA","CIVIL LINES","KASHMERE GATE","CHANDNI CHOWK",
"CHAWRI BAZAR","NEW DELHI (YELLOW & AIRPORT LINE)","RAJIV CHOWK","PATEL CHOWK",
"CENTRAL SECRETARIAT","UDYOG BHAWAN","LOK KALYAN MARG","JOR BAGH","DILLI HAAT - INA",
"AIIMS","GREEN PARK","HAUZ KHAS","MALVIYA NAGAR","SAKET","QUTAB MINAR",
"CHHATARPUR","SULTANPUR","GHITORNI","ARJAN GARH","GURU DRONACHARYA","SIKANDERPUR",
"M.G. ROAD","IFFCO CHOWK","MILLENNIUM CITY CENTRE GURUGRAM"
    };
    yellowline.distance = 1.27;
    yellowline.time = 1.86;
    yellowline.interchanges = 8;
    yellowline.name = "yellowline";
    m.insert(yellowline);

    line blueline2;
    blueline2.stations = {
     "YAMUNA BANK","LAXMI NAGAR","NIRMAN VIHAR","PREET VIHAR","KARKARDUMA","ANAND VIHAR ISBT",
     "KAUSHAMBI","VAISHALI"
   };
    blueline2.distance = 1.02;
    blueline2.time = 1.62;
    blueline2.interchanges = 3;
    blueline2.name = "blueline2";
    m.insert(blueline2);

    line greenline;
    greenline.stations = {
"KIRTI NAGAR",
"SATGURU RAM SINGH MARG",
"INDERLOK",
"ASHOK PARK MAIN",
"PUNJABI BAGH",
"PUNJABI BAGH WEST",
"SHIVAJI PARK",
"MADIPUR",
"PASCHIM VIHAR EAST",
"PASCHIM VIHAR WEST",
"PEERAGARHI",
"UDYOG NAGAR",
"MAHARAJA SURAJMAL STADIUM",
"NANGLOI",
"NANGLOI RAILWAY STATION",
"RAJDHANI PARK",
"MUNDKA",
"MUNDKA INDUSTRIAL AREA (MIA)",
"GHEVRA METRO STATION",
"TIKRI KALAN",
"TIKRI BORDER",
"PANDIT SHREE RAM SHARMA",
"BAHADURGARH CITY",
"BRIG. HOSHIAR SINGH"
   };
   greenline.distance = 1.16;
   greenline.time = 1.5;
   greenline.interchanges = 4;
   greenline.name = "greenline";
   m.insert(greenline);

line pinkline;
pinkline.stations = {
"MAJLIS PARK",
"AZADPUR",
"SHALIMAR BAGH",
"NETAJI SUBHASH PLACE",
"SHAKURPUR",
"PUNJABI BAGH WEST",
"ESI-BASAIDARAPUR",
"RAJOURI GARDEN",
"MAYAPURI",
"NARAINA VIHAR",
"DELHI CANTT.",
"DURGABAI DESHMUKH SOUTH CAMPUS",
"SIR M. VISHWESHWARAIAH MOTI BAGH",
"BHIKAJI CAMA PLACE",
"SAROJINI NAGAR",
"DILLI HAAT - INA",
"SOUTH EXTENSION",
"LAJPAT NAGAR",
"VINOBAPURI",
"ASHRAM",
"SARAI KALE KHAN - NIZAMUDDIN",
"MAYUR VIHAR-I",
"MAYUR VIHAR POCKET-1",
"TRILOKPURI-SANJAY LAKE",
"EAST VINOD NAGAR-MAYUR VIHAR-II",
"MANDAWALI-WEST VINOD NAGAR",
"I.P. EXTENSION",
"ANAND VIHAR ISBT",
"KARKARDUMA",
"KARKARDUMA COURT",
"KRISHNA NAGAR",
"EAST AZAD NAGAR",
"WELCOME",
"JAFRABAD",
"MAUJPUR-BABARPUR",
"GOKULPURI",
"JOHRI ENCLAVE",
"SHIV VIHAR"
};
pinkline.distance = 1.51;
pinkline.time = 2.21;
pinkline.interchanges = 11;
pinkline.name = "pinkline";
m.insert(pinkline);

line greyline;
greyline.stations = {
  "DWARKA","NANGLI","NAJAFGARH","DHANSA BUS STAND"
};
greyline.distance = 1.25;
greyline.time = 2.5;
greyline.interchanges = 1;
greyline.name = "greyline";
m.insert(greyline);

line orangeline;
orangeline.stations = {
"NEW DELHI (YELLOW & AIRPORT LINE)",
"SHIVAJI STADIUM",
"DHAULA KUAN",
"DELHI AEROCITY",
"AIRPORT (T-3)",
"DWARKA SECTOR-21",
"YASHOBHOOMI DWARKA SECTOR-25",
};
orangeline.distance = 3.55;
orangeline.time = 2.71;
orangeline.interchanges = 3;
orangeline.name = "orangeline";
m.insert(orangeline);

line rapidmetro;
rapidmetro.stations = {
"SECTOR 55-56",
"SECTOR-54 CHOWK",
"SECTOR-53-54",
"SECTOR-42-43",
"PHASE-1",
"SIKANDERPUR",
"PHASE-2",
"BELVEDERE TOWERS",
"CYBER CITY",
"MOULSARI AVENUE",
"PHASE-3"
};
rapidmetro.distance = 0.96;
rapidmetro.time = 1.27;
rapidmetro.interchanges = 1;
rapidmetro.name = "rapidmetro";
m.insert(rapidmetro);

// processing
graph.resize(300, list<station_info>());

int count = 0;

for(int i = 0; i < m.size(); i++){
   line cur = m.line_details(i);
   station_info a;
   a.distance = cur.distance;
   a.time = cur.time;
   a.interchanges = cur.interchanges;
   a.linename = cur.name;
  for(int j = 0; j < cur.stations.size() - 1; j++){
    station_info x = a, y = a; // x & y are edges
    x.name = cur.stations[j]; // change x's name acc.
    y.name = cur.stations[j + 1]; // change y's station name
    bool a = stationsmap.count(x.name), b = stationsmap.count(y.name);
    if(a && b){
        x.dest = stationsmap[x.name].dest, y.dest = stationsmap[y.name].dest;
        get_edges(x, y);
    }
   else if(b){
      x.dest = count++;
      y.dest = stationsmap[y.name].dest;
      get_edges(x, y);
      stationsmap[x.name] = x;
      allstations.push_back(x);
    }
    else if(a){
        x.dest = stationsmap[x.name].dest;
        y.dest = count++;
        get_edges(x, y);
        stationsmap[y.name] = y;
        allstations.push_back(y);
    }
    else{
        x.dest = count++;
        y.dest = count++;
        get_edges(x, y);
        stationsmap[x.name] = x;
        stationsmap[y.name] = y;
        allstations.push_back(x);
        allstations.push_back(y);
    }
  }
}




string from, to;
cout<<"From : ";
getline(cin, from);
cout<<"To : ";
getline(cin, to);
station_info from_station, to_station;
from_station.name = make_uppercase(from);
from_station.dest = stationsmap[from].dest;
to_station.name = make_uppercase(to);
to_station.dest = stationsmap[to].dest;

stack<station_info> result = finder(from_station, to_station);

cout<<endl;
cout<<endl; // Time & Distance
cout<<"Total Time : "<<total_time<<" min"<<endl;
cout<<"Total Distance : "<<total_distance<<" km"<<endl;
cout<<endl;

string curr_line;
int ctr = 1;
int r_size = result.size();
while(!result.empty()){

    if(ctr > 1 && ctr < r_size){ // line change logic ...
    if(ctr == 2) curr_line = result.top().linename;
    if(result.top().linename != curr_line){
        curr_line = result.top().linename;
        cout<<"( Change to "<<curr_line<<" )"<<endl;
           cout<<"\n";
    cout<<"     |     "<<endl;
    cout<<"\n";
    }
    }
    ctr++;

    cout<<result.top().name<<endl;
    if(result.size() > 1){
    cout<<"\n";
    cout<<"     |     "<<endl;
    cout<<"\n";
    }
    result.pop();

}
    return 0;
}