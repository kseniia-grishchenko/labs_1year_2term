#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "g2.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

void print_author_and_task(){
    std::cout<<"Kseniia Grishchenko, K-14\nVariant 58: calculate the distance between the point and the segment\n";
};

string get_file_path(const string& type) {
    string s;
    cout << "Enter the path of " + type + " file: " << endl;
    getline(cin, s);
    if(s == ""){
        if(type == "input") {
            return "../in.txt";
        }
        else
            return "../out.txt";
    }
    return s;
}

ifstream open_input(const string& input_file){
    ifstream fin;
    fin.open(input_file);
    if(!fin.is_open()){
        open_input(get_file_path("input"));
    }
    return fin;
}

Segment get_segment(ifstream& fin) {
    double x1, y1, x2, y2;
    fin >> x1 >> y1 >> x2 >> y2;
    if (Point {x1, y1} == Point{x2, y2}) {
        throw (Point{x1, y1});
    }
    else
        return Segment{x1, y1, x2, y2};
}

Point get_point(ifstream& fin) {
    double x1, y1;
    fin >> x1 >> y1;
    return Point{x1, y1};
}

void process_data(ifstream& fin, ofstream& fout) {
    Segment segment;
    try {
        segment = get_segment(fin);
    }
    catch (Point& p) {
        cout << "You entered two equal points for segment! The next piece of data will be processed\n";
        cout << p.get_x() << " " << p.get_y() << endl;
        cout << endl;
        fin = open_input((get_file_path("input")));
        process_data(fin, fout);
    }

    vector<Point> points;
    while(!fin.eof()) {
        points.push_back(get_point(fin));
    }
    points.pop_back();
    fout << segment.get_first().get_x() << " " << segment.get_first().get_y() << " " << segment.get_second().get_x() << " " << segment.get_second().get_y() << endl;
    for(auto point:points){
        fout << point.get_x() << " " << point.get_y() << " - " ;
        fout << segment.calculate_distance(point) << endl;
    }
}


int main(){
    ifstream fin;
    ofstream fout;
    string input_file;
    string output_file;

    print_author_and_task();

    input_file = get_file_path("input");
    output_file = get_file_path("output");

    fin = open_input(input_file);
    fout.open(output_file);

    process_data(fin, fout);


}

