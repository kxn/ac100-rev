// func get_acs_timeout @ 00483000 size=20

char get_acs_timeout(void)

{
  char cVar1;
  
  cVar1 = DAT_0076757e;
  if (DAT_0076757e == '\0') {
    cVar1 = '\x05';
  }
  return cVar1;
}

