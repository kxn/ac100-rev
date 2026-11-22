// func ac_cmcc_radius_result @ 00439c60 size=420

undefined4 ac_cmcc_radius_result(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint *__s;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_50 [32];
  uint local_30;
  undefined2 local_2c;
  undefined2 local_2a;
  byte local_22;
  
  __s = (uint *)FUN_00408450(0x10,0x9a6);
  uVar1 = 0xffffffff;
  if (__s != (uint *)0x0) {
    memset(__s,0,0x10);
    memset(auStack_50,0,0x34);
    iVar2 = wportal_db_cmcc_get_wq(param_1,auStack_50);
    if (iVar2 == 0) {
      uVar3 = *__s;
    }
    else {
      if ((param_2 == 0) || (iVar2 = wportal_db_cmcc_get_wq_by_ip(param_2,auStack_50), iVar2 != 0))
      {
        if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d Get cmcc wq error\n","ac_cmcc_radius_result",0x9b9);
        }
        _ac_cmcc_send_pkt(__s,auStack_50,4,4);
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      uVar3 = *__s;
    }
    *__s = uVar3 & 0xffffff | 0x1000000;
    *__s = (uint)local_22 << 8 | uVar3 & 0xff00ff | 0x1000000;
    *(undefined2 *)(__s + 1) = local_2a;
    if (local_22 == 0) {
      *(undefined2 *)((int)__s + 6) = local_2c;
    }
    __s[2] = local_30;
    *(ushort *)((int)__s + 0xe) = *(ushort *)((int)__s + 0xe) & 0xff00;
    _ac_cmcc_send_pkt(__s,auStack_50,4,param_3);
    wportal_db_cmcc_del_wq(param_1);
    if (param_2 != 0) {
      wportal_db_cmcc_del_wq_by_ip(param_2);
    }
    FUN_00407df0(__s);
    uVar1 = 0;
  }
  return uVar1;
}

