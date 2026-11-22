// func _radius_setnonblocking @ 0043c128 size=136

void _radius_setnonblocking(int param_1)

{
  uint uVar1;
  int iVar2;
  char *__s;
  
  uVar1 = fcntl(param_1,3);
  if ((int)uVar1 < 0) {
    __s = "fcntl(sock,GETFL)";
  }
  else {
    iVar2 = fcntl(param_1,4,uVar1 | 0x80);
    if (-1 < iVar2) {
      return;
    }
    __s = "fcntl(sock,SETFL,opts)";
  }
  perror(__s);
  return;
}

