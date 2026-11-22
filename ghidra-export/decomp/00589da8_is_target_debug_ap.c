// func is_target_debug_ap @ 00589da8 size=260

bool is_target_debug_ap(void)

{
  pthread_t pVar1;
  bool bVar3;
  uint uVar2;
  int iVar4;
  int iVar5;
  
  uVar2 = debug_ip;
  if ((debug_ip != 0) || (bVar3 = true, debug_port != 0)) {
    pVar1 = pthread_self();
    iVar4 = 0;
    if (*(int *)(ac + 0x18) == 0) {
      bVar3 = false;
    }
    else {
      iVar5 = *(int *)(ac + 0x20);
      while (pVar1 != *(pthread_t *)(iVar5 + iVar4 * 4)) {
        iVar4 = iVar4 + 1;
        if (iVar4 == *(int *)(ac + 0x18)) {
          return false;
        }
        iVar5 = *(int *)(ac + 0x20);
      }
      if (uVar2 == 0) {
        uVar2 = (uint)(debug_port ^ *(ushort *)(*(int *)(ac + 0x1c) + iVar4 * 0xa0 + 0x90));
      }
      else {
        iVar4 = *(int *)(ac + 0x1c) + iVar4 * 0xa0;
        if (debug_port != 0) {
          if (*(char *)(iVar4 + 0x7c) != '\x01') {
            return false;
          }
          if (uVar2 != *(uint *)(iVar4 + 0x80)) {
            return false;
          }
          return *(ushort *)(iVar4 + 0x90) == debug_port;
        }
        if (*(char *)(iVar4 + 0x7c) != '\x01') {
          return false;
        }
        uVar2 = uVar2 ^ *(uint *)(iVar4 + 0x80);
      }
      bVar3 = uVar2 == 0;
    }
  }
  return bVar3;
}

