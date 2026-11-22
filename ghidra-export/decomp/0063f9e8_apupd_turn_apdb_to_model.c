// func apupd_turn_apdb_to_model @ 0063f9e8 size=496

undefined4 apupd_turn_apdb_to_model(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  size_t __n;
  void *__src;
  int iVar3;
  uint uVar4;
  char cVar5;
  undefined4 uVar6;
  ushort local_18;
  ushort uStack_16;
  char *__s;
  
  uStack_16 = 0xffff;
  local_18 = 0xffff;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar6 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_turn_apdb_to_model",0x10f8);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_2 + 300) = *(undefined4 *)(param_1 + 0x74);
    *(undefined4 *)(param_2 + 0x130) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(param_2 + 0x134) = *(undefined4 *)(param_1 + 0x7c);
    *(char *)(param_2 + 0x138) = (char)*(undefined4 *)(param_1 + 0x80);
    __s = (char *)(param_1 + 0x11b);
    if (*(char *)(param_1 + 0x11b) == '\0') {
      __s = (char *)(param_1 + 0xda);
    }
    __n = strlen(__s);
    if ((int)__n < 0x41) {
      cVar5 = *(char *)(param_1 + 0x11b);
    }
    else if (g_apupd_error == 0) {
      cVar5 = *(char *)(param_1 + 0x11b);
    }
    else {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        cVar5 = *(char *)(param_1 + 0x11b);
      }
      else {
        printf("[APUPD_ERROR]%32s() %05d: model name is too long(%d)\r\n","apupd_turn_apdb_to_model"
               ,0x1107,__n);
        cVar5 = *(char *)(param_1 + 0x11b);
      }
    }
    __src = (void *)(param_1 + 0x11b);
    if (cVar5 == '\0') {
      __src = (void *)(param_1 + 0xda);
    }
    memcpy((void *)(param_2 + 0x5c),__src,__n);
    uVar4 = 0;
    *(undefined4 *)(param_2 + 0xa0) = *(undefined4 *)(param_1 + 0x160);
    iVar3 = param_2;
    while (uVar4 < *(uint *)(param_1 + 0x160)) {
      *(undefined2 *)(iVar3 + 0xa4) = *(undefined2 *)(*(int *)(param_1 + 0x164) + uVar4 * 0x38);
      uVar1 = *(ushort *)(iVar3 + 0xa4);
      uVar2 = *(ushort *)(*(int *)(param_1 + 0x164) + uVar4 * 0x38 + 2);
      *(ushort *)(iVar3 + 0xa6) = uVar2;
      if ((uVar1 < local_18) || ((uVar1 == local_18 && (uVar2 < uStack_16)))) {
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 4;
        uStack_16 = uVar2;
        local_18 = uVar1;
      }
      else {
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 4;
      }
    }
    sprintf((char *)(param_2 + 0xc4),"%s_v%d_fit.bin",param_2 + 0x5c,(uint)local_18);
    uVar6 = 0;
    memcpy((void *)(param_2 + 0x119),(void *)(param_1 + 0x84),0x10);
  }
  return uVar6;
}

