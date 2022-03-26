# Libft
C 프로그래밍을 하면서 자주 사용할 함수 구현

### libc functions

memset

bzero

memcpy

memccpy

memmove

memchr

memcmp

strlen

strlcpy

strlcat

strchr

strrchr

strnstr

strncmp

atoi

isalpha

isdigit

isalnum

isascii

isprint

toupper

tolower

calloc

strdup

### Addtonal fuctions

substr

strjoin

strtrim

split

itoa

strmapi

putchar_fd

putstr_fd

putendl_fd

putnbr_fd


### Linked list fuctions


```
typedef struct s_list
{
  void          *content;
  struct s_list *next;
}t_list;
``` 

lstnew

lstadd_front

lstsize

lstlast

lstadd_back

lstdelone

lstclear

lstiter

lstmap
