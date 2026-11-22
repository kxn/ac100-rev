// func apmngr_hdap_peer_mac_get @ 005482e8 size=112

undefined4 apmngr_hdap_peer_mac_get(void *param_1,void *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (void *)0x0) && (param_2 != (void *)0x0)) {
    memcpy(param_2,param_1,5);
    bVar1 = *(byte *)((int)param_1 + 5);
    if (bVar1 < 0xfe) {
      *(byte *)((int)param_2 + 5) = bVar1 + 2;
      uVar2 = 2;
    }
    else {
      *(byte *)((int)param_2 + 5) = bVar1 - 2;
      uVar2 = 1;
    }
  }
  return uVar2;
}

