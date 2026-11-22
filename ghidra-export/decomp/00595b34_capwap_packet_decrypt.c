// func capwap_packet_decrypt @ 00595b34 size=804

undefined4 capwap_packet_decrypt(int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t __n;
  int iVar4;
  void *__dest;
  char *__format;
  undefined4 uVar5;
  void *__src;
  undefined1 auStack_58 [68];
  
  if (((param_1 == 0) || (param_2 == (int *)0x0)) || (*param_2 == 0)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d input error.\n";
    uVar5 = 0x88;
  }
  else {
    if (*(int *)(param_1 + 0x50) != 0) {
      __src = (void *)(*(int *)(param_1 + 0x4c) + 0x104);
      iVar2 = FUN_004081b0(*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x40));
      if (iVar2 == 0) {
        puVar3 = *(undefined4 **)(param_1 + 0x50);
      }
      else {
        iVar4 = *(int *)(*(int *)(iVar2 + 0xc) + 0x18);
        param_2[7] = *(int *)(*(int *)(iVar2 + 0xc) + 0x1c);
        param_2[6] = iVar4;
        iVar4 = *(int *)(*(int *)(iVar2 + 0xc) + 0x10);
        param_2[5] = *(int *)(*(int *)(iVar2 + 0xc) + 0x14);
        param_2[4] = iVar4;
        puVar3 = *(undefined4 **)(param_1 + 0x50);
      }
      __n = gnutls_record_recv(*puVar3,__src,0xcc00);
      if ((int)__n < 1) {
        memset(auStack_58,0,0x40);
        iVar2 = *(int *)(param_1 + 0x50);
        FUN_00408190(*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0xc),
                     *(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x14),
                     *(undefined4 *)(iVar2 + 0x18),auStack_58,0x40,"---");
        if ((capwap_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          uVar1 = *(ushort *)(*(int *)(param_1 + 0x50) + 0x1c);
          uVar5 = FUN_00407fe0(param_1 + 0x58);
          printf("[CW_WARNING]%32s():%4d SSL read failed[%s:%d],starting free pkt list[total:%u]\n",
                 "capwap_packet_decrypt",0xc4,auStack_58,(uint)uVar1,uVar5);
        }
        while (iVar2 = FUN_004081b0(param_1 + 0x58), iVar2 != 0) {
          cw_pkt_buf_destroy(*(undefined4 *)(iVar2 + 0xc));
          FUN_00408500(iVar2);
          FUN_00407df0(iVar2);
        }
        return 0xffffffff;
      }
      if (param_2[2] < (int)__n) {
        FUN_00407df0(*param_2);
        iVar2 = FUN_00408450(__n,0xd4);
        *param_2 = iVar2;
        if (iVar2 == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          __format = "[CW_ERROR]%32s():%4d malloc failed.\n";
          uVar5 = 0xd6;
          goto LAB_00595c70;
        }
        param_2[2] = __n;
        __dest = (void *)*param_2;
      }
      else {
        __dest = (void *)*param_2;
      }
      *(short *)(param_2 + 1) = (short)__n;
      memcpy(__dest,__src,__n);
      return 0;
    }
    iVar2 = FUN_004081b0(param_1 + 0x58);
    if (iVar2 != 0) {
      iVar4 = *(int *)(*(int *)(iVar2 + 0xc) + 0x10);
      param_2[5] = *(int *)(*(int *)(iVar2 + 0xc) + 0x14);
      param_2[4] = iVar4;
      iVar4 = *(int *)(*(int *)(iVar2 + 0xc) + 0x18);
      param_2[7] = *(int *)(*(int *)(iVar2 + 0xc) + 0x1c);
      param_2[6] = iVar4;
      iVar4 = *param_2;
      *(undefined2 *)(param_2 + 1) = *(undefined2 *)(*(int *)(iVar2 + 0xc) + 4);
      param_2[2] = *(int *)(*(int *)(iVar2 + 0xc) + 8);
      *param_2 = **(int **)(iVar2 + 0xc);
      **(int **)(iVar2 + 0xc) = iVar4;
      FUN_00408500(iVar2);
      cw_pkt_buf_destroy(*(undefined4 *)(iVar2 + 0xc));
      FUN_00407df0(iVar2);
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d no packet to be readed\n";
    uVar5 = 0x93;
  }
LAB_00595c70:
  printf(__format,"capwap_packet_decrypt",uVar5);
  return 0xffffffff;
}

