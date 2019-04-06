#include <iostream>
#include <string>

using namespace std;

class Movie
{
    string title;
    string director;
    double rating;

public:
    Movie()
    {

    };

    Movie(string title, string director, double rating)
    {
        this->title = title;
        this->director = director;
        this->rating = rating;
    }

    void setData(string title, string director, double rating)
    {
        this->title = title;
        this->director = director;
        this->rating = rating;
    }

    string getTitle()
    {
        return this->title;
    }

    string getDirector()
    {
        return this->director;
    }

    double getRating()
    {
        return this->rating;
    }
};

int main()
{
    Movie movie_1;
    Movie movie_2("지오스톰", "딘 데블린", 8.34);

    movie_1.setData("타이타닉", "제임스 카메론", 9.5);

    cout << "영화 #1" << endl;
    cout << "영화 제목 : " << movie_1.getTitle() << endl;
    cout << "영화 감독 : " << movie_1.getDirector() << endl;
    cout << "영화 평점 : " << movie_1.getRating() << endl;

    cout << endl;

    cout << "영화 #2" << endl;
    cout << "영화 제목 : " << movie_2.getTitle() << endl;
    cout << "영화 감독 : " << movie_2.getDirector() << endl;
    cout << "영화 평점 : " << movie_2.getRating() << endl;

    return 0;
}
