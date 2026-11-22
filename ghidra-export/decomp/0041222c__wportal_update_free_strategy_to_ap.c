// func _wportal_update_free_strategy_to_ap @ 0041222c size=1180

int _wportal_update_free_strategy_to_ap(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *__s;
  undefined4 *__s_00;
  undefined4 uVar3;
  undefined4 *puVar4;
  size_t __n;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  if (*(int *)(param_1 + 0x98) == 1) {
    __n = 0xb4;
  }
  else {
    if (*(int *)(param_1 + 0x98) != 2) {
      if (wportal_err_switch == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      printf("[WPORTAL_ERR]%s()/%d Free strategy entry type %d is not allowed.\n",
             "_wportal_update_free_strategy_to_ap",0x4f2,*(undefined4 *)(param_1 + 0x98));
      return 0;
    }
    __n = 0xc0;
  }
  __s = (undefined4 *)FUN_00408450(__n,0x4f9);
  iVar2 = -1;
  if (__s == (undefined4 *)0x0) {
    return -1;
  }
  memset(__s,0,__n);
  __s_00 = (undefined4 *)FUN_00408450(0x4c,0x501);
  if (__s_00 == (undefined4 *)0x0) goto LAB_00412454;
  memset(__s_00,0,0x4c);
  *__s = param_2;
  __s[5] = 1;
  __s_00[5] = 1;
  *__s_00 = param_2;
  if (*(int *)(param_1 + 0x98) == 1) {
    __s[6] = *(undefined4 *)(param_1 + 0x9c);
    cVar1 = *(char *)(param_1 + 0xa0);
    *(char *)(__s + 7) = cVar1;
    if (cVar1 == '\0') {
      __s[0xd] = *(undefined4 *)(param_1 + 0xb8);
      __s[0xe] = *(undefined4 *)(param_1 + 0xbc);
      __s[0x12] = *(undefined4 *)(param_1 + 0xcc);
      __s[0x11] = *(undefined4 *)(param_1 + 200);
      __s[0x13] = *(undefined4 *)(param_1 + 0xd0);
      __s[8] = *(undefined4 *)(param_1 + 0xa4);
      __s[9] = *(undefined4 *)(param_1 + 0xa8);
      memcpy(__s + 0xb,(void *)(param_1 + 0xb0),6);
      __s[0x10] = *(undefined4 *)(param_1 + 0xc4);
      __s[0xf] = *(undefined4 *)(param_1 + 0xc0);
      __s[10] = *(undefined4 *)(param_1 + 0xac);
    }
    else {
      __s[8] = *(undefined4 *)(param_1 + 0xa4);
      __s[9] = *(undefined4 *)(param_1 + 0xa8);
      __s[10] = *(undefined4 *)(param_1 + 0xac);
      memcpy(__s + 0xb,(void *)(param_1 + 0xb0),6);
      memcpy((void *)((int)__s + 0x32),(void *)(param_1 + 0xb6),0x80);
    }
    if (g_portal_auth_mode == 0) {
      __s[10] = 0;
      goto LAB_004123d4;
    }
    iVar2 = *(int *)(param_1 + 0x98);
  }
  else {
    __s[6] = *(undefined4 *)(param_1 + 0x9c);
    cVar1 = *(char *)(param_1 + 0xa0);
    *(char *)(__s + 7) = cVar1;
    if (cVar1 == '\0') {
      memcpy((void *)((int)__s + 0x3e),(void *)(param_1 + 0xc2),0x10);
      __s[0x14] = *(undefined4 *)(param_1 + 0xd4);
      __s[0x18] = *(undefined4 *)(param_1 + 0xe4);
      __s[0x17] = *(undefined4 *)(param_1 + 0xe0);
      __s[0x19] = *(undefined4 *)(param_1 + 0xe8);
      memcpy(__s + 8,(void *)(param_1 + 0xa4),0x10);
      __s[0xc] = *(undefined4 *)(param_1 + 0xb4);
      __s[0x16] = *(undefined4 *)(param_1 + 0xdc);
      __s[0x15] = *(undefined4 *)(param_1 + 0xd8);
      memcpy(__s + 0xe,(void *)(param_1 + 0xbc),6);
      __s[0xd] = *(undefined4 *)(param_1 + 0xb8);
    }
    else {
      memcpy(__s + 8,(void *)(param_1 + 0xa4),0x10);
      __s[0xc] = *(undefined4 *)(param_1 + 0xb4);
      __s[0xd] = *(undefined4 *)(param_1 + 0xb8);
      memcpy(__s + 0xe,(void *)(param_1 + 0xbc),6);
      memcpy((void *)((int)__s + 0x3e),(void *)(param_1 + 0xc2),0x80);
    }
    if (g_portal_auth_mode == 0) {
      __s[0xd] = 0;
    }
LAB_004123d4:
    iVar2 = *(int *)(param_1 + 0x98);
  }
  if ((iVar2 == 1) && (*(char *)(param_1 + 0xa0) == '\0')) {
    __s_00[6] = *(undefined4 *)(param_1 + 0x9c);
    __s_00[7] = *(undefined4 *)(param_1 + 0xa4);
    __s_00[8] = *(undefined4 *)(param_1 + 0xa8);
    __s_00[9] = *(undefined4 *)(param_1 + 0xac);
    memcpy(__s_00 + 10,(void *)(param_1 + 0xb0),6);
    __s_00[0xc] = *(undefined4 *)(param_1 + 0xb8);
    __s_00[0xd] = *(undefined4 *)(param_1 + 0xbc);
    __s_00[0xe] = *(undefined4 *)(param_1 + 0xc0);
    __s_00[0xf] = *(undefined4 *)(param_1 + 0xc4);
    __s_00[0x10] = *(undefined4 *)(param_1 + 200);
    __s_00[0x11] = *(undefined4 *)(param_1 + 0xcc);
    __s_00[0x12] = *(undefined4 *)(param_1 + 0xd0);
    if (g_portal_auth_mode == 0) {
      __s_00[9] = 0;
    }
  }
  serv_wtp_address_arg_init(&local_30);
  if (*(int *)(param_1 + 0x98) == 1) {
    uVar3 = 2;
LAB_0041262c:
    apmngr_db_get_all_addr_by_capacity(&local_30,1,1,0x15f0000,1,uVar3);
  }
  else if (*(int *)(param_1 + 0x98) == 2) {
    uVar3 = 0x21;
    goto LAB_0041262c;
  }
  if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d before _wportal_update_to_ap.\n",
           "_wportal_update_free_strategy_to_ap",0x587);
  }
  iVar2 = _wportal_update_to_ap(__s,__n,&local_30,1);
  serv_wtp_address_arg_destroy(&local_30);
  puVar4 = __s_00;
  if ((*(char *)(param_1 + 0xa0) == '\0') && (*(int *)(param_1 + 0x98) == 1)) {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    serv_wtp_address_arg_init(&local_30);
    apmngr_db_get_all_addr_by_capacity(&local_30,0,1,0x15f0000,1,2);
    iVar2 = _wportal_update_to_ap(__s_00,0x4c,&local_30,1);
    if (iVar2 != 0) {
      puVar4 = (undefined4 *)0x0;
      FUN_00407df0(__s_00);
    }
    serv_wtp_address_arg_destroy(&local_30);
    if (puVar4 == (undefined4 *)0x0) goto LAB_00412454;
  }
  FUN_00407df0(puVar4);
LAB_00412454:
  FUN_00407df0(__s);
  return iVar2;
}

