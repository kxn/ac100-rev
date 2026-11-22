// func _wportal_common_free_strategy_traverse_func @ 0041721c size=884

undefined4 _wportal_common_free_strategy_traverse_func(int *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  void *__src;
  undefined4 *puVar4;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  if (g_max_free_strategy <= param_1[1]) {
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[WPORTAL_DBG]%s()/%d Free strategy exceed count MAX: %d\n",
           "_wportal_common_free_strategy_traverse_func",0x1755,g_max_free_strategy);
    return 0xffffffff;
  }
  if (*param_1 == 1) {
    if ((*(int *)(param_2 + 0x98) != 1) && (*(int *)(param_2 + 0x98) != 3)) {
      return 0;
    }
    puVar4 = (undefined4 *)param_1[2];
    *puVar4 = *(undefined4 *)(param_2 + 0x9c);
    cVar1 = *(char *)(param_2 + 0xa0);
    *(char *)(puVar4 + 1) = cVar1;
    if (cVar1 == '\0') {
      puVar4[7] = *(undefined4 *)(param_2 + 0xb8);
      puVar4[8] = *(undefined4 *)(param_2 + 0xbc);
      puVar4[0xc] = *(undefined4 *)(param_2 + 0xcc);
      puVar4[0xb] = *(undefined4 *)(param_2 + 200);
      puVar4[0xd] = *(undefined4 *)(param_2 + 0xd0);
      puVar4[2] = *(undefined4 *)(param_2 + 0xa4);
      puVar4[3] = *(undefined4 *)(param_2 + 0xa8);
      memcpy(puVar4 + 5,(void *)(param_2 + 0xb0),6);
      puVar4[10] = *(undefined4 *)(param_2 + 0xc4);
      puVar4[9] = *(undefined4 *)(param_2 + 0xc0);
      puVar4[4] = *(undefined4 *)(param_2 + 0xac);
    }
    else {
      puVar4[2] = *(undefined4 *)(param_2 + 0xa4);
      puVar4[3] = *(undefined4 *)(param_2 + 0xa8);
      puVar4[4] = *(undefined4 *)(param_2 + 0xac);
      memcpy(puVar4 + 5,(void *)(param_2 + 0xb0),6);
      memcpy((void *)((int)puVar4 + 0x1a),(void *)(param_2 + 0xb6),0x80);
    }
    if (g_portal_auth_mode == 0) {
      puVar4[4] = 0;
    }
    iVar3 = param_1[2] + 0x9c;
    goto LAB_0041740c;
  }
  if (*param_1 != 2) {
    return 0;
  }
  if (1 < *(int *)(param_2 + 0x98) - 2U) {
    return 0;
  }
  puVar4 = (undefined4 *)param_1[2];
  if (*(int *)(param_2 + 0x98) == 2) {
    *puVar4 = *(undefined4 *)(param_2 + 0x9c);
    cVar1 = *(char *)(param_2 + 0xa0);
    *(char *)(puVar4 + 1) = cVar1;
    if (cVar1 != '\0') {
      memcpy(puVar4 + 2,(void *)(param_2 + 0xa4),0x10);
      puVar4[6] = *(undefined4 *)(param_2 + 0xb4);
      puVar4[7] = *(undefined4 *)(param_2 + 0xb8);
      memcpy(puVar4 + 8,(void *)(param_2 + 0xbc),6);
      __src = (void *)(param_2 + 0xc2);
      goto LAB_00417544;
    }
    memcpy((void *)((int)puVar4 + 0x26),(void *)(param_2 + 0xc2),0x10);
    puVar4[0xe] = *(undefined4 *)(param_2 + 0xd4);
    puVar4[0x12] = *(undefined4 *)(param_2 + 0xe4);
    puVar4[0x11] = *(undefined4 *)(param_2 + 0xe0);
    puVar4[0x13] = *(undefined4 *)(param_2 + 0xe8);
    memcpy(puVar4 + 2,(void *)(param_2 + 0xa4),0x10);
    puVar4[6] = *(undefined4 *)(param_2 + 0xb4);
    memcpy(puVar4 + 8,(void *)(param_2 + 0xbc),6);
    puVar4[0x10] = *(undefined4 *)(param_2 + 0xdc);
    puVar4[0xf] = *(undefined4 *)(param_2 + 0xd8);
    uVar2 = *(undefined4 *)(param_2 + 0xb8);
LAB_00417358:
    puVar4[7] = uVar2;
  }
  else {
    *puVar4 = *(undefined4 *)(param_2 + 0x9c);
    cVar1 = *(char *)(param_2 + 0xa0);
    *(char *)(puVar4 + 1) = cVar1;
    if (cVar1 == '\0') {
      memset((void *)((int)puVar4 + 0x26),0,0x10);
      puVar4[0xe] = *(undefined4 *)(param_2 + 0xbc);
      puVar4[0x12] = *(undefined4 *)(param_2 + 0xcc);
      puVar4[0x11] = *(undefined4 *)(param_2 + 200);
      puVar4[0x13] = *(undefined4 *)(param_2 + 0xd0);
      memset(puVar4 + 2,0,0x10);
      puVar4[6] = *(undefined4 *)(param_2 + 0xa8);
      memcpy(puVar4 + 8,(void *)(param_2 + 0xb0),6);
      puVar4[0x10] = *(undefined4 *)(param_2 + 0xc4);
      puVar4[0xf] = *(undefined4 *)(param_2 + 0xc0);
      uVar2 = *(undefined4 *)(param_2 + 0xac);
      goto LAB_00417358;
    }
    memset(puVar4 + 2,0,0x10);
    puVar4[6] = *(undefined4 *)(param_2 + 0xa8);
    puVar4[7] = *(undefined4 *)(param_2 + 0xac);
    memcpy(puVar4 + 8,(void *)(param_2 + 0xb0),6);
    __src = (void *)(param_2 + 0xb6);
LAB_00417544:
    memcpy((void *)((int)puVar4 + 0x26),__src,0x80);
  }
  if (g_portal_auth_mode == 0) {
    puVar4[7] = 0;
  }
  iVar3 = param_1[2] + 0xa8;
LAB_0041740c:
  param_1[2] = iVar3;
  param_1[1] = param_1[1] + 1;
  return 0;
}

