// func pull_func @ 00597400 size=436

size_t pull_func(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  size_t __n;
  void *__s2;
  undefined1 auStack_28 [16];
  
  iVar1 = FUN_004081b0(*(undefined4 *)(param_1 + 0x3c));
  memcpy(auStack_28,&DAT_006e3520,0xe);
  if (iVar1 != 0) {
    uVar3 = (uint)*(ushort *)(*(undefined4 **)(iVar1 + 0xc) + 1);
    if (3 < uVar3) {
      __s2 = (void *)**(undefined4 **)(iVar1 + 0xc);
      iVar2 = memcmp(&DAT_006e3578,__s2,4);
      if (iVar2 == 0) {
        uVar3 = uVar3 - 4;
        if (uVar3 <= param_3) {
          memcpy(param_2,(void *)((int)__s2 + 4),uVar3);
          FUN_00408500(iVar1);
          cw_pkt_buf_destroy(*(undefined4 *)(iVar1 + 0xc));
          FUN_00407df0(iVar1);
          return uVar3;
        }
        if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_DEBUG]%32s():%4d packet length(%d) exceeds restore size(%d)\n","pull_func",
                 0x7a,*(ushort *)(*(int *)(iVar1 + 0xc) + 4) - 4,param_3);
        }
        FUN_00408500(iVar1);
        cw_pkt_buf_destroy(*(undefined4 *)(iVar1 + 0xc));
        FUN_00407df0(iVar1);
        goto LAB_005974bc;
      }
    }
    FUN_00408500(iVar1);
    cw_pkt_buf_destroy(*(undefined4 *)(iVar1 + 0xc));
    FUN_00407df0(iVar1);
    if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_DEBUG]%32s():%4d not DTLS packet\n","pull_func",0x70);
    }
  }
LAB_005974bc:
  __n = 0xe;
  if (param_3 < 0xf) {
    __n = param_3;
  }
  memcpy(param_2,auStack_28,__n);
  return __n;
}

