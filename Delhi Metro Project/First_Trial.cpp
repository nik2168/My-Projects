#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<map>
using namespace std;

vector<string> allstations;
unordered_map<string, int> stationsmap;
double total_distance;
vector<list<pair<double, int>>> graph;
void get_edges(int i, double distance, int j){
    graph[i].push_back(make_pair(distance, j));
    graph[j].push_back(make_pair(distance, i));
}

void display(){
    for(int i = 0; i < graph.size(); i++){
        cout<<i<<" -> ";
        for(auto x : graph[i]){
            cout<<"("<<x.first<<", "<<x.second<<")";
        }
        cout<<endl;
    }
}


stack<string> finder(int src, int dst){
        stack<string> result;
        unordered_map<int, double> m; // will store src & dist
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q; // will store dist & destination
        unordered_set<int> vis; // visited nodes
        vector<int> par(300, 0); // parent node;
        for(int i = 0; i < 300; i++){
                m[i] = INT_MAX;
        }
        q.push(make_pair(0, src));
        m[src] = 0;
        par[src] = 0;
        while(!q.empty()){
                pair<double, int> cur = q.top();
                q.pop();
                if(vis.count(cur.second) == 1) continue;
                vis.insert(cur.second);
                for(auto x : graph[cur.second]){
                        double td = cur.first + x.first;
                 if(m[x.second] > td){
                        m[x.second] = td;
                        q.push(make_pair(td, x.second));
                        par[x.second] = cur.second;
                                }
                        }
        }
        total_distance = m[dst];
        int i = dst;
        result.push(allstations[i]);
        while(i != src){
                result.push(allstations[par[i]]);
                i = par[i];
        }
        return result;
}



int main(){

    // intersecting stations
    unordered_map<string, int> interstations;
    interstations["DWARKA SECTOR-21"] = 0;
    interstations["DWARKA"] = 0;
    interstations["JANAKPURI WEST"] = 0;
    interstations["RAJOURI GARDEN"] = 0;
    interstations["KIRTI NAGAR"] = 0;
    interstations["RAJIV CHOWK"] = 0;
    interstations["MANDI HOUSE"] = 0;
    interstations["YAMUNA BANK"] = 0;
    interstations["MAYUR VIHAR-I"] = 0;
    interstations["BOTANICAL GARDEN"] = 0;
    interstations["WELCOME"] = 0;
    interstations["KASHMERE GATE"] = 0;
    interstations["INDERLOK"] = 0;
    interstations["NETAJI SUBHASH PLACE"] = 0;
    interstations["JANAKPURI WEST"] = 0;
    interstations["HAUZ KHAS"] = 0;
    interstations["KALKAJI MANDIR"] = 0;
    interstations["BOTANICAL GARDEN"] = 0;
    interstations["KASHMERE GATE"] = 0;
    interstations["MANDI HOUSE"] = 0;
    interstations["CENTRAL SECRETARIAT"] = 0;
    interstations["LAJPAR NAGAR"] = 0;
    interstations["KALKAJI MANDIR"] = 0;
    interstations["AZADPUR"] = 0;
    interstations["KASHMERE GATE"] = 0;
    interstations["NEW DELHI (YELLOW & AIRPORT LINE)"] = 0;
    interstations["RAJIV CHOWK"] = 0;
    interstations["CENTRAL SECRETARIAT"] = 0;
    interstations["DILLI HAAT - INA"] = 0;
    interstations["HAUZ KHAS"] = 0;
    interstations["SIKANDERPUR"] = 0;
    interstations["YAMUNA BANK"] = 0;
    interstations["KARKARDUMA"] = 0;
    interstations["ANAND VIHAR ISBT"] = 0;
    interstations["KIRTI NAGAR"] = 0;
    interstations["INDERLOK"] = 0;
    interstations["ASHOK PARK MAIN"] = 0;
    interstations["PUNJABI BAGH WEST"] = 0;
    interstations["AZADPUR"] = 0;
    interstations["NETAJI SUBHASH PLACE"] = 0;
    interstations["PUNJABI BAGH WEST"] = 0;
    interstations["RAJOURI GARDEN"] = 0;
    interstations["DURGABAI DESHMUKH SOUTH CAMPUS"] = 0;
    interstations["DILLI HAAT-INA"] = 0;
    interstations["LAJPAT NAGAR"] = 0;
    interstations["MAYUR VIHAR-1"] = 0;
    interstations["ANAND VIHAR ISBT"] = 0;
    interstations["KARKARDUMA"] = 0;
    interstations["WELCOME"] = 0;
    interstations["DWARKA"] = 0;
    interstations["NEW DELHI (YELLOW & AIRPORT LINE)"] = 0;
    interstations["DHAULA KUAN"] = 0;
    interstations["DWARKA SECTOR-21"] = 0;
    interstations["SIKANDERPUR"] = 0;

    // blue line stations
    vector<string> blueline = {"DWARKA SECTOR-21",
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
    
    // blue line stations time, dist & interchanges
    double bluelinesize = blueline.size();
    double bluelinedist = 1.11;
    double bluelinetime = 1.7;
    double bluelineinterchange = 10;


    // Red Line
    vector<string> redline = {
    "SHAHEED STHAL(NEW BUS ADDA)","HINDON RIVER","ARTHALA","MOHAN NAGAR","SHYAM PARK",
    "MAJOR MOHIT SHARMA RAJENDRA NAGAR","RAJ BAGH","SHAHEED NAGAR","DILSHAD GARDEN",
    "JHILMIL","MANSAROVAR PARK","SHAHDARA","WELCOME","SEELAMPUR","SHASTRI PARK",
    "KASHMERE GATE","TIS HAZARI","PULBANGASH","PRATAP NAGAR","SHASTRI NAGAR",
    "INDERLOK","KANHAIYA NAGAR","KESHAV PURAM","NETAJI SUBHASH PLACE","KOHAT ENCLAVE",
    "PITAMPURA","ROHINI EAST","ROHINI WEST","RITHALA"    
    };

    double redlinedist = 1.15;
    double redlinetime = 1.6;
    double redlinesize = redline.size();
    double redlineinterchange = 4;


    // Magenta Line
    vector<string> magentaline = {
    "JANAKPURI WEST","DABRI MOR-JANAKPURI SOUTH","DASHRATHPURI","PALAM","SADAR BAZAR CANTONMENT",
    "TERMINAL 1-IGI AIRPORT","SHANKAR VIHAR","VASANT VIHAR","MUNIRKA","R.K.PURAM",
    "IIT","HAUZ KHAS","PANCHSHEEL PARK","CHIRAG DELHI","GREATER KAILASH","NEHRU ENCLAVE",
    "KALKAJI MANDIR","OKHLA NSIC","SUKHDEV VIHAR","JAMIA MILLIA ISLAMIA","OKHLA VIHAR",
    "JASOLA VIHAR SHAHEEN BAGH","KALINDI KUNJ","OKHLA BIRD SANCTUARY","BOTANICAL GARDEN"
    };
    // Magenta Line Details
    double magentalinedist = 1.36;
    double magentalinetime = 2.4;
    double magentalinesize = magentaline.size();
    double magentalineinterchange = 4;


    // Violet Line
    vector<string> violetline = {
    "KASHMERE GATE","LAL QUILA","JAMA MASJID","DELHI GATE","ITO","MANDI HOUSE","JANPATH",
    "CENTRAL SECRETARIAT","KHAN MARKET","JLN STADIUM","JANGPURA","LAJPAT NAGAR","MOOLCHAND",
    "KAILASH COLONY","NEHRU PLACE","KALKAJI MANDIR","GOVIND PURI","HARKESH NAGAR OKHLA",
    "JASOLA-APOLLO","SARITA VIHAR","MOHAN ESTATE","TUGHLAKABAD STATION","BADARPUR BORDER",
    "SARAI","NHPC CHOWK","MEWALA MAHARAJPUR","SECTOR-28","BADKAL MOR","OLD FARIDABAD",
    "NEELAM CHOWK AJRONDA","BATA CHOWK","ESCORTS MUJESAR","SANT SURDAS (SIHI)","RAJA NAHAR SINGH (BALLABHGARH)"
    };
    // VIOLET LINE DETAILS
    double violetlinedist =  1.32;
    double violetlinetime = 1.88;
    double violetlinesize = violetline.size();
    double violetlineinterchange = 5; 

     
    // Yellow Line
    vector<string> yellowline = {
    "SAMAYPUR BADLI","ROHINI SECTOR-18,19","HAIDERPUR BADLI MOR","JAHANGIRPURI",
"ADARSH NAGAR","AZADPUR","MODEL TOWN","GURU TEG BAHADUR NAGAR",
"VISHWAVIDYALAYA","VIDHAN SABHA","CIVIL LINES","KASHMERE GATE","CHANDNI CHOWK",
"CHAWRI BAZAR","NEW DELHI (YELLOW & AIRPORT LINE)","RAJIV CHOWK","PATEL CHOWK",
"CENTRAL SECRETARIAT","UDYOG BHAWAN","LOK KALYAN MARG","JOR BAGH","DILLI HAAT - INA",
"AIIMS","GREEN PARK","HAUZ KHAS","MALVIYA NAGAR","SAKET","QUTAB MINAR",
"CHHATARPUR","SULTANPUR","GHITORNI","ARJAN GARH","GURU DRONACHARYA","SIKANDERPUR",
"M.G. ROAD","IFFCO CHOWK","MILLENNIUM CITY CENTRE GURUGRAM"
    };

   // Yellow Line Details
   double yellowlinedist = 1.27;
   double yellowlinetime = 1.86;
   double yellowlinesize = yellowline.size();
   double yellowlineinterchange = 8;


   // Blue Line 2
   vector<string>blueline2 = {
     "YAMUNA BANK","LAXMI NAGAR","NIRMAN VIHAR","PREET VIHAR","KARKARDUMA","ANAND VIHAR ISBT",
     "KAUSHAMBI","VAISHALI"
   };

   //BLUELINE2 details
   double blueline2dist = 1.02;
   double blueline2time = 1.62;
   double blueline2size = blueline2.size(); 
   double blueline2interchange = 3;


   // Green Line
   vector<string> greenline = {
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

// Green Line details
double greenlinedist = 1.16;
double greenlinetime = 1.5;
double greenlinesize = greenline.size();
double greenlineinterchange = 4;


// Pink Line
vector<string> pinkline = {
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

// Pink Line Details
double pinklinedist = 1.51;
double pinklinetime = 2.21;
double pinklinesize = pinkline.size();
double pinklineinterchange = 11;


//Grey Line
vector<string> greyline = {
  "DWARKA","NANGLI","NAJAFGARH","DHANSA BUS STAND"
};

double greylinedist = 1.25;
double greylinetime = 2.5;
double greylinesize = greyline.size();
double greylineinterchange = 1;


// Orange Line / Airport Express
vector<string> orangeline = {
"NEW DELHI (YELLOW & AIRPORT LINE)",
"SHIVAJI STADIUM",
"DHAULA KUAN",
"DELHI AEROCITY",
"AIRPORT (T-3)",
"DWARKA SECTOR-21",
"YASHOBHOOMI DWARKA SECTOR-25",
};

double orangelinedist = 3.55;
double orangelinetime = 2.71;
double orangelinesize = orangeline.size();
double orangelineinterchange = 3;


//RAPID METRO LINE
vector<string> rapidmetro = {
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

//rapid metro details
double rapidmetrodist = 0.96;
double rapidmetrotime = 1.27;
double rapidmetrosize = rapidmetro.size();
double rapidmetrointerchange = 1;


// Main Code


graph.resize(300, list<pair<double, int>>());

// for blue line
for(int i = 0; i < blueline.size() - 1; i++){
    get_edges(i, bluelinedist, i + 1);
    allstations.push_back(blueline[i]);
    stationsmap[blueline[i]] = i;
}
int count = blueline.size() - 1;
 allstations.push_back(blueline[count]);
 stationsmap[blueline[count]] = count;
 count++;


// for red line
for(int i = 0; i < redline.size()-1; i++){
     if(stationsmap.count(redline[i]) == 1 && stationsmap.count(redline[i + 1]) == 1){
    get_edges(stationsmap[redline[i]], redlinedist, stationsmap[redline[i + 1]]);
    }
     else if(stationsmap.count(redline[i + 1]) == 1){
    get_edges(count, redlinedist, stationsmap[redline[i + 1]]);
    stationsmap[redline[i]] = count; 
            allstations.push_back(redline[i]);
            count++;
    }
    else if(stationsmap.count(redline[i]) == 1 ){
    get_edges(stationsmap[redline[i]], redlinedist, count + 1);
    }
    else{
            get_edges(count, redlinedist, count + 1);
            stationsmap[redline[i]] = count; 
            allstations.push_back(redline[i]);
            count++;
    }
}
if(stationsmap.count(redline[redline.size()-1]) == 0 ){
   stationsmap[redline[redline.size()-1]] = count; 
            allstations.push_back(redline[redline.size()-1]);
            count++;
}

// for magenta line
for(int i = 0; i < magentaline.size()-1; i++){
     if(stationsmap.count(magentaline[i]) == 1 && stationsmap.count(magentaline[i + 1]) == 1){
    get_edges(stationsmap[magentaline[i]], magentalinedist, stationsmap[magentaline[i + 1]]);
    }
     else if(stationsmap.count(magentaline[i + 1]) == 1){
    get_edges(count, magentalinedist, stationsmap[magentaline[i + 1]]);
    stationsmap[magentaline[i]] = count; 
            allstations.push_back(magentaline[i]);
            count++;
    }
    else if(stationsmap.count(magentaline[i]) == 1 ){
    get_edges(stationsmap[magentaline[i]], magentalinedist, count + 1);
    }
    else{
            get_edges(count, magentalinedist, count + 1);
            stationsmap[magentaline[i]] = count; 
            allstations.push_back(magentaline[i]);
            count++;
    }
}
if(stationsmap.count(magentaline[magentaline.size()-1]) == 0 ){
   stationsmap[magentaline[magentaline.size()-1]] = count; 
            allstations.push_back(magentaline[magentaline.size()-1]);
            count++;
}

// for violet line
for(int i = 0; i < violetline.size()-1; i++){
     if(stationsmap.count(violetline[i]) == 1 && stationsmap.count(violetline[i + 1]) == 1){
    get_edges(stationsmap[violetline[i]], violetlinedist, stationsmap[violetline[i + 1]]);
    }
     else if(stationsmap.count(violetline[i + 1]) == 1){
    get_edges(count, violetlinedist, stationsmap[violetline[i + 1]]);
    stationsmap[violetline[i]] = count; 
            allstations.push_back(violetline[i]);
            count++;
    }
    else if(stationsmap.count(violetline[i]) == 1 ){
    get_edges(stationsmap[violetline[i]], violetlinedist, count + 1);
    }
    else{
            get_edges(count, violetlinedist, count + 1);
            stationsmap[violetline[i]] = count; 
            allstations.push_back(violetline[i]);
            count++;
    }
}
if(stationsmap.count(violetline[violetline.size()-1]) == 0 ){
   stationsmap[violetline[violetline.size()-1]] = count; 
            allstations.push_back(violetline[violetline.size()-1]);
            count++;
}

// for yellow line
for(int i = 0; i < yellowline.size()-1; i++){
     if(stationsmap.count(yellowline[i]) == 1 && stationsmap.count(yellowline[i + 1]) == 1){
    get_edges(stationsmap[yellowline[i]], yellowlinedist, stationsmap[yellowline[i + 1]]);
    }
     else if(stationsmap.count(yellowline[i + 1]) == 1){
    get_edges(count, yellowlinedist, stationsmap[yellowline[i + 1]]);
    stationsmap[yellowline[i]] = count; 
            allstations.push_back(yellowline[i]);
            count++;
    }
    else if(stationsmap.count(yellowline[i]) == 1 ){
    get_edges(stationsmap[yellowline[i]], yellowlinedist, count + 1);
    }
    else{
            get_edges(count, yellowlinedist, count + 1);
            stationsmap[yellowline[i]] = count; 
            allstations.push_back(yellowline[i]);
            count++;
    }
}
if(stationsmap.count(yellowline[yellowline.size()-1]) == 0 ){
   stationsmap[yellowline[yellowline.size()-1]] = count; 
            allstations.push_back(yellowline[yellowline.size()-1]);
            count++;
}

// for blueline2 
for(int i = 0; i < blueline2.size()-1; i++){
     if(stationsmap.count(blueline2[i]) == 1 && stationsmap.count(blueline2[i + 1]) == 1){
    get_edges(stationsmap[blueline2[i]], blueline2dist, stationsmap[blueline2[i + 1]]);
    }
     else if(stationsmap.count(blueline2[i + 1]) == 1){
    get_edges(count, blueline2dist, stationsmap[blueline2[i + 1]]);
    stationsmap[blueline2[i]] = count; 
            allstations.push_back(blueline2[i]);
            count++;
    }
    else if(stationsmap.count(blueline2[i]) == 1 ){
    get_edges(stationsmap[blueline2[i]], blueline2dist, count + 1);
    }
    else{
            get_edges(count, blueline2dist, count + 1);
            stationsmap[blueline2[i]] = count; 
            allstations.push_back(blueline2[i]);
            count++;
    }
}
if(stationsmap.count(blueline2[blueline2.size()-1]) == 0 ){
   stationsmap[blueline2[blueline2.size()-1]] = count; 
            allstations.push_back(blueline2[blueline2.size()-1]);
            count++;
}

// for greenline 
for(int i = 0; i < greenline.size()-1; i++){
     if(stationsmap.count(greenline[i]) == 1 && stationsmap.count(greenline[i + 1]) == 1){
    get_edges(stationsmap[greenline[i]], greenlinedist, stationsmap[greenline[i + 1]]);
    }
     else if(stationsmap.count(greenline[i + 1]) == 1){
    get_edges(count, greenlinedist, stationsmap[greenline[i + 1]]);
    stationsmap[greenline[i]] = count; 
            allstations.push_back(greenline[i]);
            count++;
    }
    else if(stationsmap.count(greenline[i]) == 1 ){
    get_edges(stationsmap[greenline[i]], greenlinedist, count + 1);
    }
    else{
            get_edges(count, greenlinedist, count + 1);
            stationsmap[greenline[i]] = count; 
            allstations.push_back(greenline[i]);
            count++;
    }
}
if(stationsmap.count(greenline[greenline.size()-1]) == 0 ){
   stationsmap[greenline[greenline.size()-1]] = count; 
            allstations.push_back(greenline[greenline.size()-1]);
            count++;
}

// for pink line
for(int i = 0; i < pinkline.size()-1; i++){
     if(stationsmap.count(pinkline[i]) == 1 && stationsmap.count(pinkline[i + 1]) == 1){
    get_edges(stationsmap[pinkline[i]], pinklinedist, stationsmap[pinkline[i + 1]]);
    }
     else if(stationsmap.count(pinkline[i + 1]) == 1){
    get_edges(count, pinklinedist, stationsmap[pinkline[i + 1]]);
    stationsmap[pinkline[i]] = count; 
            allstations.push_back(pinkline[i]);
            count++;
    }
    else if(stationsmap.count(pinkline[i]) == 1 ){
    get_edges(stationsmap[pinkline[i]], pinklinedist, count + 1);
    }
    else{
            get_edges(count, pinklinedist, count + 1);
            stationsmap[pinkline[i]] = count; 
            allstations.push_back(pinkline[i]);
            count++;
    }
}
if(stationsmap.count(pinkline[pinkline.size()-1]) == 0 ){
   stationsmap[pinkline[pinkline.size()-1]] = count; 
            allstations.push_back(pinkline[pinkline.size()-1]);
            count++;
}

// for grey line
for(int i = 0; i < greyline.size()-1; i++){
     if(stationsmap.count(greyline[i]) == 1 && stationsmap.count(greyline[i + 1]) == 1){
    get_edges(stationsmap[greyline[i]], greylinedist, stationsmap[greyline[i + 1]]);
    }
     else if(stationsmap.count(greyline[i + 1]) == 1){
    get_edges(count, greylinedist, stationsmap[greyline[i + 1]]);
    stationsmap[greyline[i]] = count; 
            allstations.push_back(greyline[i]);
            count++;
    }
    else if(stationsmap.count(greyline[i]) == 1 ){
    get_edges(stationsmap[greyline[i]], greylinedist, count + 1);
    }
    else{
            get_edges(count, greylinedist, count + 1);
            stationsmap[greyline[i]] = count; 
            allstations.push_back(greyline[i]);
            count++;
    }
}
if(stationsmap.count(greyline[greyline.size()-1]) == 0 ){
   stationsmap[greyline[greyline.size()-1]] = count; 
            allstations.push_back(greyline[greyline.size()-1]);
            count++;
}

// for orange line
for(int i = 0; i < orangeline.size()-1; i++){
     if(stationsmap.count(orangeline[i]) == 1 && stationsmap.count(orangeline[i + 1]) == 1){
    get_edges(stationsmap[orangeline[i]], orangelinedist, stationsmap[orangeline[i + 1]]);
    }
     else if(stationsmap.count(orangeline[i + 1]) == 1){
    get_edges(count, orangelinedist, stationsmap[orangeline[i + 1]]);
    stationsmap[orangeline[i]] = count; 
            allstations.push_back(orangeline[i]);
            count++;
    }
    else if(stationsmap.count(orangeline[i]) == 1 ){
    get_edges(stationsmap[orangeline[i]], orangelinedist, count + 1);
    }
    else{
            get_edges(count, orangelinedist, count + 1);
            stationsmap[orangeline[i]] = count; 
            allstations.push_back(orangeline[i]);
            count++;
    }
}
if(stationsmap.count(orangeline[orangeline.size()-1]) == 0 ){
   stationsmap[orangeline[orangeline.size()-1]] = count; 
            allstations.push_back(orangeline[orangeline.size()-1]);
            count++;
}

// for rapid metro line
for(int i = 0; i < rapidmetro.size()-1; i++){
     if(stationsmap.count(rapidmetro[i]) == 1 && stationsmap.count(rapidmetro[i + 1]) == 1){
    get_edges(stationsmap[rapidmetro[i]], rapidmetrodist, stationsmap[rapidmetro[i + 1]]);
    }
     else if(stationsmap.count(rapidmetro[i + 1]) == 1){
    get_edges(count, rapidmetrodist, stationsmap[rapidmetro[i + 1]]);
    stationsmap[rapidmetro[i]] = count; 
            allstations.push_back(rapidmetro[i]);
            count++;
    }
    else if(stationsmap.count(rapidmetro[i]) == 1 ){
    get_edges(stationsmap[rapidmetro[i]], rapidmetrodist, count + 1);
    }
    else{
            get_edges(count, rapidmetrodist, count + 1);
            stationsmap[rapidmetro[i]] = count; 
            allstations.push_back(rapidmetro[i]);
            count++;
    }
}
if(stationsmap.count(rapidmetro[rapidmetro.size()-1]) == 0 ){
   stationsmap[rapidmetro[rapidmetro.size()-1]] = count; 
            allstations.push_back(rapidmetro[rapidmetro.size()-1]);
            count++;
}

string from, to;
cout<<"From : ";
cin>>from;
cout<<"To : ";
cin>>to;

stack<string> route = finder(stationsmap[from], stationsmap[to]);
while(!route.empty()){
  cout<<route.top()<<" -> ";
  route.pop();
}
cout<<endl;
cout<<"Total Distance : "<<total_distance<<"KM"<<endl;

// map<int, string> temp;

// for(auto t : stationsmap){
//   temp[t.second] = t.first;
// }
// for(auto tr : temp){
//         cout<<tr.first<<" "<<tr.second<<endl;
// }
    return 0;
}