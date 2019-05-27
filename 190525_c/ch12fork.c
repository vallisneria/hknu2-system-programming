/*
    부모가 자식 둘을 생성하고, 각 자식은 다시 자식 둘을 생성하는 프로그램 ch12fork.c를 작성하라

    - 부모는 자식 둘을 생성한 후,
      I am a parent(pid). I created two children!을 출력하고 종료한다.

    - 각 자식은 손자 둘을 생성한 후,
      I am a child(pid). I created two grandchildren!을 출력하고 종료한다.

    - 각 손자는 I am a grandchild(pid). I do not creat any descendant!를 출력하고 종료한다.
*/