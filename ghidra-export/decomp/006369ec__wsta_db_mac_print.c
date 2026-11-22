// func _wsta_db_mac_print @ 006369ec size=132

void _wsta_db_mac_print(int param_1)

{
  byte bVar1;
  char *__format;
  int iVar2;
  
  iVar2 = 0;
  do {
    __format = "%02x\r\n";
    if (iVar2 == 5) {
      bVar1 = *(byte *)(param_1 + 5);
    }
    else {
      bVar1 = *(byte *)(param_1 + iVar2);
      __format = "%02x-";
    }
    iVar2 = iVar2 + 1;
    printf(__format,(uint)bVar1);
  } while (iVar2 != 6);
  return;
}

