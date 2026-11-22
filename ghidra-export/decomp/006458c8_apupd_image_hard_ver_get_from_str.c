// func apupd_image_hard_ver_get_from_str @ 006458c8 size=1148

undefined4 apupd_image_hard_ver_get_from_str(undefined4 param_1,int *param_2)

{
  char cVar1;
  void *__s1;
  uint uVar2;
  undefined2 uVar5;
  int iVar3;
  int iVar4;
  int iVar6;
  char *pcVar7;
  char *__src;
  size_t __n;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  char *local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [11];
  
  memset(local_54,0,0x2c);
  local_64 = 0;
  local_68 = (char *)0x0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  __s1 = (void *)apupd_str_to_first_kr(param_1,&DAT_007120e8,&local_64);
  if (__s1 == (void *)0x0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[APUPD_ERROR]%32s() %05d: parse support-list str failed.\r\n";
    uVar8 = 0x513;
  }
  else {
    iVar4 = memcmp(__s1,"SupportList:",0xc);
    if (iVar4 == 0) {
      iVar4 = apupd_str_to_args(local_64,"\r\n",local_54,0xb);
      if (iVar4 == -1) {
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        pcVar7 = "[APUPD_ERROR]%32s() %05d: parse support-list failed.\r\n";
        uVar8 = 0x51e;
      }
      else {
        if (0 < iVar4) {
          puVar9 = local_54;
          iVar10 = 0;
LAB_006459ec:
          pcVar7 = (char *)*puVar9;
          do {
            local_68 = pcVar7;
            cVar1 = *local_68;
            if (cVar1 == '\0') break;
            pcVar7 = local_68 + 1;
          } while ((cVar1 == ' ') || (cVar1 == '\t'));
          do {
            if ((local_68 == (char *)0x0) || (*local_68 == '\0')) goto LAB_00645c7c;
            pcVar7 = strchr(local_68,0x3a);
            if (pcVar7 == (char *)0x0) {
              if (g_apupd_error == 0) {
                return 0xffffffff;
              }
              iVar4 = is_target_debug_ap();
              if (iVar4 == 0) {
                return 0xffffffff;
              }
              printf("[APUPD_ERROR]%32s() %05d: invalid support-list: %s\r\n",
                     "apupd_image_hard_ver_get_from_str",0x541,local_54[iVar10]);
              return 0xffffffff;
            }
            iVar3 = apupd_str_to_kr(pcVar7 + 1,".",&local_5c);
            local_60 = iVar3;
            if (iVar3 == 0) {
              if (g_apupd_error == 0) {
                return 0xffffffff;
              }
              iVar4 = is_target_debug_ap();
              if (iVar4 == 0) {
                return 0xffffffff;
              }
              pcVar7 = 
              "[APUPD_ERROR]%32s() %05d: parse major and minor of hardware version failed.\r\n";
              uVar8 = 0x548;
              goto LAB_00645b80;
            }
            while (__src = local_68, local_68 < pcVar7) {
              if (pcVar7[-1] == ' ') {
                pcVar7 = pcVar7 + -1;
              }
              else {
                if (pcVar7[-1] != '\t') break;
                pcVar7 = pcVar7 + -1;
              }
            }
LAB_00645a28:
            if (__src < pcVar7) {
              if (*__src == ' ') {
                __src = __src + 1;
              }
              else {
                if (*__src != '\t') {
                  iVar6 = *param_2;
                  goto LAB_00645a4c;
                }
                __src = __src + 1;
              }
              goto LAB_00645a28;
            }
            iVar6 = *param_2;
LAB_00645a4c:
            uVar2 = (int)pcVar7 - (int)__src >> 0x1f;
            __n = (uVar2 ^ (int)pcVar7 - (int)__src) - uVar2;
            if (0x40 < (int)__n) {
              __n = 0x40;
            }
            memcpy((void *)((int)param_2 + iVar6 * 0x46 + 4),__src,__n);
            iVar6 = *param_2;
            uVar5 = apupd_str_to_ul(iVar3,0,10);
            *(undefined2 *)((int)param_2 + iVar6 * 0x46 + 0x46) = uVar5;
            iVar3 = *param_2;
            uVar5 = apupd_str_to_ul(local_5c,0,10);
            *(undefined2 *)((int)param_2 + iVar3 * 0x46 + 0x48) = uVar5;
            if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[APUPD_DEBUG]%32s() %05d: model_name:%s\r\n",
                     "apupd_image_hard_ver_get_from_str",0x55a,(int)param_2 + *param_2 * 0x46 + 4);
            }
            if (g_apupd_debug == 0) {
              iVar3 = *param_2;
            }
            else {
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                iVar3 = *param_2;
              }
              else {
                printf("[APUPD_DEBUG]%32s() %05d: ver: %d.%d\n\r\n",
                       "apupd_image_hard_ver_get_from_str",0x55b,
                       (uint)*(ushort *)((int)param_2 + *param_2 * 0x46 + 0x46),
                       (uint)*(ushort *)((int)param_2 + *param_2 * 0x46 + 0x48));
                iVar3 = *param_2;
              }
            }
            *param_2 = iVar3 + 1;
            apupd_str_to_kr(local_5c,&DAT_007122b8,&local_68);
          } while( true );
        }
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        pcVar7 = "[APUPD_ERROR]%32s() %05d: no support AP list.\r\n";
        uVar8 = 0x523;
      }
    }
    else {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      pcVar7 = "[APUPD_ERROR]%32s() %05d: check support-list failed.\r\n";
      uVar8 = 0x518;
    }
  }
LAB_00645b80:
  printf(pcVar7,"apupd_image_hard_ver_get_from_str",uVar8);
  return 0xffffffff;
LAB_00645c7c:
  iVar10 = iVar10 + 1;
  puVar9 = puVar9 + 1;
  if (iVar10 == iVar4) {
    return 0;
  }
  goto LAB_006459ec;
}

