// func wportal_db_ssid_rdt_set @ 00432e34 size=264

undefined4 wportal_db_ssid_rdt_set(uint param_1,void *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  void *__dest;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if ((-1 < (int)param_1) && (uVar2 = wserv_profile_get_max_wservice(), param_1 < uVar2)) {
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    __dest = *(void **)(wportal_wserv_node + param_1 * 8 + 4);
    if (__dest == (void *)0x0) {
      FUN_00407f30(wportal_rdt_mutex);
    }
    else {
      *(undefined4 *)((int)__dest + 0x15c) = *(undefined4 *)((int)param_2 + 0x15c);
      uVar3 = 0;
      *(undefined4 *)((int)__dest + 0x160) = *(undefined4 *)((int)param_2 + 0x160);
      memcpy(__dest,param_2,0x80);
      memcpy((void *)((int)__dest + 0x100),(void *)((int)param_2 + 0x100),0x32);
      memcpy((void *)((int)__dest + 0x80),(void *)((int)param_2 + 0x80),0x80);
      *(undefined4 *)((int)__dest + 0x154) = *(undefined4 *)((int)param_2 + 0x154);
      *(undefined4 *)((int)__dest + 0x158) = *(undefined4 *)((int)param_2 + 0x158);
      memcpy((void *)((int)__dest + 0x134),(void *)((int)param_2 + 0x134),0x20);
      uVar1 = wportal_rdt_mutex;
      *(undefined4 *)((int)__dest + 0x164) = *(undefined4 *)((int)param_2 + 0x164);
      FUN_00407f30(uVar1);
    }
  }
  return uVar3;
}

