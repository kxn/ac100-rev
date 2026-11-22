// func cw_pkt_frag @ 005961d4 size=1292

undefined4 cw_pkt_frag(undefined4 *param_1,int *param_2)

{
  ushort uVar1;
  size_t __n;
  int iVar2;
  void *__s;
  void *__s_00;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t __n_00;
  char *__format;
  undefined4 uVar7;
  char *pcVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  void *__src;
  int local_50;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar7 = 0x305;
    pcVar8 = "NULL != session";
LAB_005965e4:
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_pkt_frag",uVar7,pcVar8);
    return 0xffffffff;
  }
  if (param_2 == (int *)0x0) {
    uVar7 = 0x306;
    pcVar8 = "NULL != pkt_buff";
    goto LAB_005965e4;
  }
  if (*(ushort *)(param_2 + 1) < 9) {
    uVar7 = 0x307;
    pcVar8 = "pkt_buff->len > CW_HDR_LEN";
    goto LAB_005965e4;
  }
  pcVar8 = (char *)*param_1;
  uVar10 = param_1[0xb];
  if ((int)pcVar8 < (int)(uint)*(ushort *)(param_2 + 1)) {
    if (*param_2 == 0) {
      __format = "[ASSERT]%32s():%4d assert(%s) failed\n";
      uVar7 = 0x20e;
      pcVar8 = "NULL != pkt_buff->buf";
    }
    else {
      iVar4 = cw_header_flag_f_get();
      if (iVar4 == 0) {
        uVar1 = *(ushort *)(param_2 + 1);
        __n = cw_header_length_get(*param_2);
        uVar12 = (int)pcVar8 - __n & 0xfffffff8;
        if (uVar12 != 0) {
          local_50 = 0;
          iVar11 = 0;
          iVar4 = uVar1 - __n;
          if (uVar12 == 0) {
            trap(7);
          }
          iVar2 = *param_2;
          iVar4 = iVar4 / (int)uVar12 + (uint)(iVar4 % (int)uVar12 != 0);
          iVar5 = iVar4 + -1;
          __src = (void *)(iVar2 + __n);
          while( true ) {
            if (iVar4 <= iVar11) {
              if (0xfffe < (int)param_1[0xb]) {
                param_1[0xb] = 0;
                return 0;
              }
              param_1[0xb] = param_1[0xb] + 1;
              return 0;
            }
            __s = (void *)FUN_00408450(0x10,0x22d);
            if (__s == (void *)0x0) {
              if (capwap_err_switch == 0) goto LAB_00596530;
              iVar4 = is_target_debug_ap();
              if (iVar4 == 0) goto LAB_00596530;
              printf("[CW_ERROR]%32s():%4d pkt_node malloc failed\n","cw_frag_list_write",0x22f);
              goto LAB_00596530;
            }
            memset(__s,0,0x10);
            __s_00 = (void *)FUN_00408450(0x28,0x234);
            *(void **)((int)__s + 0xc) = __s_00;
            if (__s_00 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(__s), iVar4 != 0)) {
                printf("[CW_ERROR]%32s():%4d pkt_node malloc failed\n","cw_frag_list_write",0x236);
              }
              goto LAB_00596554;
            }
            iVar6 = (int)__src - (int)(iVar2 + __n);
            memset(__s_00,0,0x28);
            piVar9 = *(int **)((int)__s + 0xc);
            __n_00 = __n + uVar12;
            if (iVar11 == iVar5) {
              __n_00 = local_50 + (uint)uVar1;
            }
            iVar3 = FUN_00408450(__n_00,0x240);
            *piVar9 = iVar3;
            if (iVar3 == 0) break;
            memset((void *)**(undefined4 **)((int)__s + 0xc),0,__n_00);
            memcpy((void *)**(undefined4 **)((int)__s + 0xc),(void *)*param_2,__n);
            cw_header_flag_f_set(**(undefined4 **)((int)__s + 0xc),1);
            cw_header_fragid_set(**(undefined4 **)((int)__s + 0xc),uVar10 & 0xffff);
            if (iVar6 < 0) {
              iVar6 = iVar6 + 7;
            }
            cw_header_fragoffset_set(**(undefined4 **)((int)__s + 0xc),(uint)(iVar6 << 0xd) >> 0x10)
            ;
            piVar9 = *(int **)((int)__s + 0xc);
            if (iVar11 == iVar5) {
              cw_header_flag_l_set(*piVar9,1);
              piVar9 = *(int **)((int)__s + 0xc);
            }
            iVar11 = iVar11 + 1;
            memcpy((void *)(*piVar9 + __n),__src,__n_00 - __n);
            *(short *)(*(int *)((int)__s + 0xc) + 4) = (short)__n_00;
            FUN_004086b0(param_1 + 0xc,__s);
            local_50 = local_50 - uVar12;
            __src = (void *)((int)__src + uVar12);
          }
          if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[CW_ERROR]%32s():%4d pkt_node malloc failed\n","cw_frag_list_write",0x242);
          }
          FUN_00407df0(*(undefined4 *)((int)__s + 0xc));
LAB_00596554:
          while( true ) {
            FUN_00407df0(__s);
LAB_00596530:
            __s = (void *)FUN_004081b0(param_1 + 0xc);
            if (__s == (void *)0x0) break;
            FUN_00408500(__s);
            cw_pkt_buf_destroy(*(undefined4 *)((int)__s + 0xc));
          }
          goto LAB_00596468;
        }
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_00596468;
        __format = "[CW_ERROR]%32s():%4d MTU[%d] too less\n";
        uVar7 = 0x219;
      }
      else {
        __format = "[ASSERT]%32s():%4d assert(%s) failed\n";
        uVar7 = 0x20f;
        pcVar8 = "0 == cw_header_flag_f_get(pkt_buff->buf)";
      }
    }
  }
  else {
    __format = "[ASSERT]%32s():%4d assert(%s) failed\n";
    uVar7 = 0x20d;
    pcVar8 = "pkt_buff->len > mtu";
  }
  printf(__format,"cw_frag_list_write",uVar7,pcVar8);
LAB_00596468:
  if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[CW_ERROR]%32s():%4d packet frag failed\n","cw_pkt_frag",0x30d);
  }
  return 0xffffffff;
}

