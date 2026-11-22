// func _wportal_free_strategy_transfer_v4_to_v6 @ 00417590 size=420

undefined4 _wportal_free_strategy_transfer_v4_to_v6(void *param_1,void *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    uVar3 = 0xffffffff;
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Invalid params.\n","_wportal_free_strategy_transfer_v4_to_v6",
             0x13a0);
    }
  }
  else {
    memset(param_2,0,0x144);
    memcpy(param_2,param_1,0x96);
    *(undefined4 *)((int)param_2 + 0x98) = 2;
    *(undefined4 *)((int)param_2 + 0x9c) = *(undefined4 *)((int)param_1 + 0x9c);
    cVar1 = *(char *)((int)param_1 + 0xa0);
    *(char *)((int)param_2 + 0xa0) = cVar1;
    if (cVar1 == '\0') {
      memcpy((void *)((int)param_2 + 0xbc),(void *)((int)param_1 + 0xb0),6);
      memset((void *)((int)param_2 + 0xa4),0,0x10);
      *(undefined4 *)((int)param_2 + 0xb4) = *(undefined4 *)((int)param_1 + 0xa8);
      *(undefined4 *)((int)param_2 + 0xd8) = *(undefined4 *)((int)param_1 + 0xc0);
      *(undefined4 *)((int)param_2 + 0xdc) = *(undefined4 *)((int)param_1 + 0xc4);
      memset((void *)((int)param_2 + 0xc2),0,0x10);
      *(undefined4 *)((int)param_2 + 0xd4) = *(undefined4 *)((int)param_1 + 0xbc);
      *(undefined4 *)((int)param_2 + 0xe0) = *(undefined4 *)((int)param_1 + 200);
      *(undefined4 *)((int)param_2 + 0xe4) = *(undefined4 *)((int)param_1 + 0xcc);
      *(undefined4 *)((int)param_2 + 0xe8) = *(undefined4 *)((int)param_1 + 0xd0);
      *(undefined4 *)((int)param_2 + 0xb8) = *(undefined4 *)((int)param_1 + 0xac);
    }
    else {
      if (cVar1 != '\x01') {
        return 0;
      }
      memcpy((void *)((int)param_2 + 0xbc),(void *)((int)param_1 + 0xb0),6);
      memset((void *)((int)param_2 + 0xa4),0,0x10);
      *(undefined4 *)((int)param_2 + 0xb4) = *(undefined4 *)((int)param_1 + 0xa8);
      *(undefined4 *)((int)param_2 + 0xb8) = *(undefined4 *)((int)param_1 + 0xac);
      memcpy((void *)((int)param_2 + 0xc2),(void *)((int)param_1 + 0xb6),0x80);
    }
    uVar3 = 0;
    if (g_portal_auth_mode == 0) {
      *(undefined4 *)((int)param_2 + 0xb8) = 0;
    }
  }
  return uVar3;
}

