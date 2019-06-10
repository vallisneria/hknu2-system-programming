/*
    자식 프로세스에서 임의의 char를 부모프로세스로 보내면
    대문자로 바꾸어 자식 프로세스로 보낸다.

    예를 들어(자식 101, 부모 100)

    PID 101 sent 'a'
    PID 100 received 'a'
    PID 100 sent 'A'
    PID 101 received 'A'
*/