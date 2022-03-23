#include "doctest.h"
#include "Notebook.hpp"
#include <string>
using ariel::Direction;

TEST_CASE("good writing, good reading, good erasing"){
    ariel::Notebook notebook;

    notebook.write(1,1,1,ariel::Direction::Horizontal,"gilad");
    CHECK(notebook.read(1,1,1,ariel::Direction::Horizontal,5)=="gilad");
    CHECK(notebook.read(1,1,3,ariel::Direction::Horizontal,5)=="lad__");
    CHECK(notebook.read(1,1,1,ariel::Direction::Vertical,5)=="g____");
    notebook.write(1,2,1,ariel::Direction::Horizontal,"david");
    CHECK(notebook.read(1,2,1,ariel::Direction::Horizontal,5)=="david");
    CHECK(notebook.read(1,2,2,ariel::Direction::Horizontal,5)=="avid_");
    CHECK(notebook.read(1,1,1,ariel::Direction::Vertical,5)=="gd___");
    CHECK(notebook.read(1,2,1,ariel::Direction::Vertical,5)=="d____");
    CHECK(notebook.read(1,3,1,ariel::Direction::Vertical,5)=="_____");
    notebook.erase(1,1,1,ariel::Direction::Horizontal,2);
    CHECK(notebook.read(1,1,1,ariel::Direction::Horizontal,5)=="~~lad");
    CHECK(notebook.read(1,1,1,ariel::Direction::Vertical,5)=="~d___");

}

TEST_CASE("bad writing, bad reading, bad erasing"){
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.write(1,1,98,ariel::Direction::Horizontal,"gilad"));
    notebook.write(1,1,1,ariel::Direction::Horizontal,"gilad");
    CHECK_THROWS(notebook.erase(1,1,98,ariel::Direction::Horizontal,10));
    CHECK(notebook.read(1,1,1,ariel::Direction::Horizontal,5)=="david");
    CHECK(notebook.read(1,1,3,ariel::Direction::Horizontal,5)=="gilad");
    CHECK(notebook.read(1,1,1,ariel::Direction::Vertical,5)=="g____");
    notebook.write(1,2,1,ariel::Direction::Horizontal,"david");
    CHECK(notebook.read(1,2,1,ariel::Direction::Horizontal,5)=="gilad");
    CHECK(notebook.read(1,2,2,ariel::Direction::Horizontal,5)=="gilad");
    CHECK(notebook.read(1,1,1,ariel::Direction::Vertical,5)=="david");
    CHECK(notebook.read(1,1,98,ariel::Direction::Horizontal,5)=="gilad");
    CHECK(notebook.read(1,1,1,ariel::Direction::Vertical,5)=="~d___");
}