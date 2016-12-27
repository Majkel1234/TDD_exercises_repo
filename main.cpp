#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <tuple>
#include <deque>
#include <regex>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])                                                    //ITERATORY
{                                                                       //vector - random access
    //EXERCISE 1                                                        //list   - bidirectional (input + output + forward + mozliwosc dekrementacji)
    std::array<int,10> _array;
    _array.fill(5);                                                     //Kontenery asocjacyjne (zwykle) - bidirectional
    _array[3] = 3;                                                      //Kontenery asocjacyjne (unordered'y) - forward iterator
    std::array<int,10> _array2;
    swap(_array,_array2);
    std::cout<<"First array: "<<std::endl;
    for(const auto &el : _array) std::cout<<el<<" ";                    //Unordered'y:
    std::cout<<std::endl;                                                       // - wszystkie el. zawsze const
    for(const auto &el : _array2) std::cout<<el<<" ";                           // - elementy zorganizowane w kosze
    std::cout<<"\n\n"<<std::endl;                                               // - funkcja hashujaca

    //Ciekawsze funkcje
    //Lista:
    std::list<double> _list{1.0,2.0,3.0,4.0,5.0};
    auto _listIter = _list.begin();
    std::advance(_listIter,3);                                  //std::advance(iter,n); - przesuwa podany iterator o n pozycji
    _list.splice(_listIter,std::list<double>{3.1,3.3,3.5});     //splice(); - przenosi elementy ze zrodla i wstawia do listy na dana pozycje
    for(const auto &el : _list){
        std::cout<<el<<" ";
    }
    std::cout<<std::endl;
    std::list<int> _mergeList1{1,3,5,7,9}, _mergeList2{2,4,6,8,10};
    _mergeList1.merge(_mergeList2);                             //merge(); - przenosi elementy ze zrodla i wstawia do listy na odpowiednie pozycje
    for(const auto &el : _mergeList1) std::cout<<el<<" ";                   //(na bazie ich wartosci [domyslnego predykatu])
    std::cout<<std::endl;

    std::set<int> _set{1,2,3,4,5,6,7};
    auto _setLowerBound = _set.lower_bound(4);                  //lower_bound(); - zwraca iterator na 'poczatek zakresu' o danej wart. (pierwszy el.)
    auto _setUpperBound = _set.upper_bound(4);                  //upper_bound(); - zwraca iterator 'za koniec zakresu' o danej wart.
    std::cout<<"Lower_bound for value 4: "<<*_setLowerBound<<"\nUpper_bound for value 4: "<<*_setUpperBound<<std::endl;

    //EXERCISE 5
    std::unordered_set<int> _uSet{1,2,3,4,5,6,7};                               //funkcje 'koszy'
    std::cout<<"Value 4 is located at bucket: "<<_uSet.bucket(4)<<std::endl;
    std::cout<<"Then, size of this bucket is: "<<_uSet.bucket_size(4)<<std::endl;
    std::cout<<"The number of all the buckets in this container: "<<_uSet.bucket_count()<<std::endl;

    //EXERCISE 6
    std::forward_list<int> _fList{1,2,3,4,5,6,7};
    auto _itFirst = std::begin(_fList);
    auto _itLast = std::end(_fList);
    std::cout<<"Forward list's size: "<<std::distance(_itFirst, _itLast)<<std::endl;
    auto _itFifthElement = _itFirst;
    std::advance(_itFifthElement,4);
    std::cout<<"Forward list's fifth element: "<<*_itFirst<<std::endl;
    std::cout<<"Distance from first to fifth element: "<<std::distance(_itFirst, _itFifthElement)<<std::endl;

    //# std::bind(); - opakowuje pierwszy argument (funkcje/funktor/lambde) w funktor, ze zmienionymi regulami przekazywania argumentow
    auto _lambda = [](int a,int b)->bool{return a>b;};
    using namespace placeholders;
    auto _wrappedLambda = std::bind(_lambda,_2,_1); //sztywno podana wart. = sztywny arg; _x = ten arg. bedziemy musieli zawsze podawac i zostanie
    std::cout<<"15 vs 10: "<<_wrappedLambda(10,15)<<std::endl;   //on przypisany do argumentu opakowanej 'funkcji' o podanym numerze
                                    //pierwszy arg = 15; drugi = 10
        //! Za pomoca tej funkcji mozemy opakowac metode 'operator()' danej klasy


    //# std::function(); - opakowuje argument (funkcje/obiekt z op.()/lambde) w funktor (bez zadnej ingerencji w kwestie przekazywania argumentow)
    auto _unaryLambdaPred = [](int x)->bool{return x%2 == 0;};                          //[w przeciwienstwie do 'std::bind()']
    auto _lambdaAsFunctor = std::function<bool(int)>(_unaryLambdaPred);
    std::cout<<"Checking if 15 is even number: "<<_lambdaAsFunctor(15)<<"\n..so maybe 18: "<<_lambdaAsFunctor(18)<<std::endl;

    //# std::generate(); - generuje wartosci dla zakresu, za pomoca otrzymanej funkcji
    std::vector<int> intVect(10);
    int counter = 0;
    auto _counterLambda = [&counter]{return ++counter;};//lambda z domknieciem, bez nawiasow argumentow {skoro nie przyjmujemy argumentow}
    std::generate(std::begin(intVect), std::end(intVect),_counterLambda);
    for(const auto &el : intVect) std::cout<<el<<" ";
            // (funkcja 'generate_n()' robi to samo, dla pierwszych n argumentow)

    //# std::accumulate(); - sumuje wartosci zakresu do podanej wartosci poczatkowej
    int initValue = 100;
    std::vector<int> _myValuesVect{10,20,30,40,50};
    std::cout<<"\nThe sum of initValue 100 and group of my values: "<<std::accumulate(std::begin(_myValuesVect), std::end(_myValuesVect),initValue)
            <<std::endl;            // [init = 100] + 10 + 20 + 30 + 40 + 50 = 250

    //# std::inner_product(); - funkcja sumujaca wynik mnozenia elementow na tych samych pozycjach w dwoch zbiorach. Operacje sumujaca (3ci arg.)
        // wynik operacji dokonanej na parach elementow (4ty argument) mozna dowolnie zmieniac.
    std::vector<int> innerVect1{1,2,3,4,5}, innerVect2{10,20,30,40,50};
    int innerInitValue = 100;                                           //domyslnie: sumuje wyniki mnozenia par (i dodaje do poczatkowej wart. 100)
    auto innerResultValue = std::inner_product(innerVect1.begin(), innerVect1.end(), innerVect2.begin(),innerInitValue);
    std::cout<<"Wynik sumy iloczynu par + 100: "<<innerResultValue<<std::endl;//[100] + 10(1*10) + 40(2*20) + 90(3*30) + 160(4*40) + 250(5*50) = 650
        //zmiana operacji
    auto innerResultValue2 =                                                     //(pocz. wart. = 100)  ..odejmowanie..   ..wynikow dzielenia
            std::inner_product(innerVect2.begin(), innerVect2.end(), innerVect1.begin(),innerInitValue, std::minus<int>(), std::divides<int>());
                                                                              //[100] - 10(10/1) - 10(20/2) - 10(30/3) - 10(40/4) - 10(50/5) = 50
    std::cout<<"Wynik odejmowania ilorazu par od liczby 100: "<<innerResultValue2<<std::endl;

    //# TUPLE
    tuple<int,char> _tupleClassic{10,'A'};
    auto _tupleMake = std::make_tuple(10,"Elo co tam",1.1);            //std::make_tuple(...) - tworzy tupla (zoptymal. jak make_shared/make_unique)
    std::cout<<"Drugi arg tupla tworzonego konstruktorem: "<<std::get<1>(_tupleClassic)<<std::endl; //std::get<pos>(tuple) - zwraca ref. el. tupla
    std::cout<<"Trzeci arg tupla tworzonego 'std::make_tuple()': "<<std::get<2>(_tupleMake)<<std::endl;
        //std::tie() - tworzy obiekt tupla, ktorego elementy staja sie referencjami do przekazanych argumentow
    int variable{10};
    char sign{'A'};
    auto tupleOfReferences = std::tie(variable,sign);   //1) tworze tupla referencji
    std::get<0>(tupleOfReferences) = 15;                //2) modyfikuje lokalne zmienne poprzez te referencje
    std::get<1>(tupleOfReferences) = 'B';
    std::cout<<"Modified local variables: ["<<variable<<" | "<<sign<<"]."<<std::endl;

    //EXERCISE 7
    auto lambdaForFunctor = [](int a, int b){return a/b;};
    auto dividingLambdaBinded = std::bind(lambdaForFunctor,_1,5); //perwszy arg. przyjmuje, drugi ma sztywna wart. 5
    vector<int> divVect{10,20,30,40,50};
    for(auto &el : divVect) el = dividingLambdaBinded(el);
    for(auto &el : divVect) std::cout<<el<<" ";
    std::cout<<std::endl;


    // # std::transform(); - wykonuje przekazana operacje dla kolejnych argumentow przekazanego zakresu, ale wynik tej operacji zapisuje w innym
    // zakresie, poczawszy od pozycji podanej iteratorem (3ci arg)
    std::vector<int> transVect1{1,2,3,4,5}, transVect2(5,0);
    auto multiplyingLambda = [](int a, int b){return a*b;};                    //tworze funktor z lambdy, ktora bedzie mnozyc x10
    std::transform(transVect1.begin(), transVect1.end(), transVect2.begin(), std::bind(multiplyingLambda,_1,10));
    for(const auto &el : transVect2){          //! Drugi zakres (w przypadku kontenera) musi miec z gory ustalony rozmiar, taki jak pierwszy
        std::cout<<el<<" "; //{1,2,3,4,5} * 5 = {10,20,30,40,50}
    }
    std::cout<<std::endl;

    // # std::mismatch(); - porownuje (odpowiadajace) elementy w obu zakresach i zwraca pierwsza niepasujaca 'pare' jako obiekt std::pair
    std::vector<int> mVect1{1,2,3,4,5}, mVect2{1,2,3,3,5};//                                              (iteratorow)
    auto mismatchElements = std::mismatch(mVect1.begin(),mVect1.end(),mVect2.begin());
    std::cout<<"Pierwsza 'para' niepasujacych do siebie elementow: ["<<*mismatchElements.first<<"|"<<*mismatchElements.second<<"]."<<std::endl;


    // # std::nth_element(); - przestawia elementy w zakresie w ten sposob, ze na wskazanej pozycji znajdzie sie ten element, ktory stalby tam
    // gdyby zbior byl posortowany, a reszta elementow, na bazie ich wartosci, bedzie ulozona przed lub za nim (ich kolejnosc nieistotna)
    std::vector<int> shuffledVect{10,15,5,0,25,20};
    std::nth_element(shuffledVect.begin(), shuffledVect.begin()+2, shuffledVect.end()); //zaznaczam trzecia pozycje (tam bedzie wlasciwy element)
    for(const auto &el : shuffledVect) std::cout<<el<<" ";// (przed: {10,15,5,0,25,20} | po: {5,0,[10],15,25,20}
    std::cout<<std::endl;

    //EXERCISE 10
    std::deque<int> _deque;
    srand(time(0));
    auto _randNumGenerator = []{return rand()%7;};
    std::generate_n(std::back_inserter(_deque),14,_randNumGenerator);           //std::back_inserter(); - tworzy iterator na 'za-ostatni' element
               //w otrzymanym kontenerze (dzieki czemu kontener bedzie 'sam sie powiekszal' poprzez, za kazdym razem, wstawianie elementu na koncu)

    // # std::remove_if(); - przestawia elementy w ten sposob, ze te, dla ktorych predykat zwroci falsz (nie do usuniecia) zostana ustawione na
    std::vector<int> remIfVector{30,10,20,1,40,3};      //poczatku kontenera; jako rezultat zwraca iterator do pierwszego 'usunietego' elementu
    auto firstRemoved = std::remove_if(remIfVector.begin(), remIfVector.end(),[](auto &x)->bool{return x>5;}); //el >=5 zostana przeniesione
    for(firstRemoved; firstRemoved != remIfVector.end(); firstRemoved++){
        std::cout<<*firstRemoved<<" ";
    }
    std::cout<<std::endl;
    for(auto &el : remIfVector) std::cout<<el<<" ";
    std::cout<<std::endl;

    // # std::rotate(); - rotuje zbior w ten sposob, ze wskazany el. staje sie jego poczatkiem a elementy przed nim zostaja dodane na koniec
    std::vector<int> rotaVect{1,2,3,4,5,6,7,8,9,10};
    std::rotate(rotaVect.begin(), rotaVect.begin()+4, rotaVect.end());//5,6,7,8,9,10,1,2,3,4
    for(const auto &el : rotaVect) std::cout<<el<<" ";
    std::cout<<std::endl;


    // # REGEX					(http://cpp0x.pl/artykuly/?id=47)
        //Polegaja na tym, ze obiekt regex przechowuje 'zakodowany' wzorzec (na podstawie swoich 'regexowych' symboli)
    //PRZYKLAD 1
    std::regex wzorzec{"\\w* to \\w*"};         //"W C++ znaki które poprzedza '\' są zarezerwowane, więc piszemy ukośnik podwójny."
    std::stringstream stringStr{"Ala ma kota\nMarek to debil\nJurek ma downa\nKrysia to kot"};
    std::string text;
    int linia = 0;
    while(std::getline(stringStr,text)){
        std::smatch wynik;                                                      //std::regex_search(zrodlo, zapiszWynik, wzorzec);
        if(std::regex_search(text,wynik,wzorzec)){
            std::cout<<"W linii "<<++linia<<" znaleziono pasujacy tekst: "<<wynik[0]<<std::endl;
        }
    }
    //PRZYKLAD 2
                        //[0-9] to to samo co '\\d' (skrot - 'digit' - cyfra)
    std::regex wzorzec2{"[0-9]{1,3}"};  //wzorzec oznacza: [0-9] - podaj liczby z zakresu; {1,3} - w ilosc od jednej do trzech max
    std::smatch wynik2; //std::smatch(); - string match (zapisuje wynik)
    std::string text2{"Elo co tam, pozdro600"};
    (std::regex_search(text2, wynik2,wzorzec2))?  std::cout<<"W tekscie 2 znaleziono fragment pasujacy do wzorca: "<<wynik2[0]<<std::endl :
                                                             std::cout<<"W tekscie 2 nie znaleziono fragmentu pasujacego do wzorca."<<std::endl;





}
