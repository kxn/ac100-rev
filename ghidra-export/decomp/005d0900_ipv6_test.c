// func ipv6_test @ 005d0900 size=1

void ipv6_test(void)

{
  char *pcVar1;
  undefined1 auStack_48 [16];
  char acStack_38 [52];
  
  memcpy(auStack_48,&UNK_006f25b0,0x10);
  memset(acStack_38,0,0x2e);
  pcVar1 = inet_ntop(10,auStack_48,acStack_38,0x2e);
  if (pcVar1 != (char *)0x0) {
    printf("IPv6 Address: %s \r\n",acStack_38);
  }
  return;
}

