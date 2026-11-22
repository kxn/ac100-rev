// func apupd_update_wtp_last_image_response_handle @ 00650670 size=1612

undefined4 apupd_update_wtp_last_image_response_handle(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 *__dest;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  undefined1 auStack_200 [64];
  char acStack_1c0 [128];
  char acStack_140 [128];
  undefined1 auStack_c0 [164];
  
  if (param_1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar7 = 0x17fd;
    goto LAB_0065097c;
  }
  iVar10 = *(int *)(param_1 + 0x30);
  iVar11 = *(int *)(iVar10 + 0x50);
  iVar1 = *(int *)(iVar11 + 0x7ec);
  if (iVar1 == 2) {
    iVar1 = *(int *)(iVar11 + 0x1ac);
  }
  else if (iVar1 == 1) {
LAB_00650780:
    iVar1 = FUN_00407fa0(*(undefined4 *)(*(int *)(param_1 + 0x34) + 0x2c),iVar10 + 0x58);
    if (iVar1 == 0) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar5 = "[APUPD_ERROR]%32s() %05d: get wtp list from hash failed\r\n";
      uVar7 = 0x180e;
      goto LAB_0065097c;
    }
    iVar1 = *(int *)(iVar1 + 0x44);
  }
  else {
    if (iVar1 == 3) {
      if (*(int *)(iVar10 + 0x54) == 1) goto LAB_00650780;
      piVar2 = *(int **)(param_1 + 0x38);
    }
    else {
      piVar2 = *(int **)(param_1 + 0x38);
    }
    if (piVar2 == (int *)0x0) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar5 = "[APUPD_ERROR]%32s() %05d: Image info should not be NULL\r\n";
      uVar7 = 0x1817;
      goto LAB_0065097c;
    }
    iVar1 = *piVar2;
  }
  if (*(int *)(iVar10 + 0x4c) != iVar1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar11 = is_target_debug_ap();
    if (iVar11 == 0) {
      return 0xffffffff;
    }
    uVar8 = *(undefined4 *)(iVar10 + 0x4c);
    pcVar5 = "[APUPD_ERROR]%32s() %05d: offset(%d) isn\'t equal to file size(%d)\r\n";
    uVar7 = 0x181f;
LAB_006509a4:
    printf(pcVar5,"apupd_update_wtp_last_image_response_handle",uVar7,uVar8,iVar1);
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 0x20) != 3) ||
     ((*(int *)(iVar10 + 0x48) != 6 && (*(int *)(iVar10 + 0x48) != 0x16)))) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    iVar1 = *(int *)(iVar10 + 0x48);
    uVar8 = *(undefined4 *)(param_1 + 0x20);
    pcVar5 = "[APUPD_ERROR]%32s() %05d: update wtp state(%d) or wtp state(%d) is invalib\r\n";
    uVar7 = 0x1826;
    goto LAB_006509a4;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x48) = 7;
  *(undefined4 *)(param_1 + 0x20) = 4;
  __dest = (undefined1 *)FUN_00408450(6,0x182e);
  if (__dest == (undefined1 *)0x0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
    uVar7 = 0x1830;
    goto LAB_0065097c;
  }
  *__dest = 0;
  __dest[1] = 0;
  __dest[2] = 0;
  __dest[3] = 0;
  __dest[4] = 0;
  __dest[5] = 0;
  memcpy(__dest,(void *)(param_1 + 0x18),6);
  if (*(int *)(param_1 + 0x28) != -1) {
    FUN_00408060();
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  }
  iVar1 = FUN_00408340(0x1a4,0,apupd_update_wtp_timer_callback,__dest,apupd_update_wtp_argv_callback
                       ,"apupd_update_wtp_last_image_response_handle",0x183c);
  *(int *)(param_1 + 0x28) = iVar1;
  if (iVar1 == -1) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n",
             "apupd_update_wtp_last_image_response_handle",0x183f);
    }
    FUN_00407df0(__dest);
    return 0xffffffff;
  }
  iVar6 = *(int *)(param_1 + 0x30);
  iVar1 = *(int *)(*(int *)(iVar6 + 0x50) + 0x7ec);
  puVar9 = (ushort *)(*(int *)(iVar6 + 0x50) + 0x1c4);
  if (iVar1 != 2) {
    if (iVar1 == 1) {
LAB_00650bf8:
      iVar1 = FUN_00407fa0(*(undefined4 *)(*(int *)(param_1 + 0x34) + 0x2c),iVar6 + 0x58);
      puVar9 = (ushort *)(iVar1 + 0x164);
      if (iVar1 == 0) {
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar5 = "[APUPD_ERROR]%32s() %05d: get wtp list failed.\r\n";
        uVar7 = 0x184e;
        goto LAB_0065097c;
      }
    }
    else {
      if (iVar1 == 3) {
        if (*(int *)(iVar6 + 0x54) == 1) goto LAB_00650bf8;
        puVar4 = *(undefined4 **)(param_1 + 0x38);
      }
      else {
        puVar4 = *(undefined4 **)(param_1 + 0x38);
      }
      puVar9 = (ushort *)(param_1 + 0x3c);
      if (puVar4 != (undefined4 *)0x0) {
        if (puVar4[1] == 0) {
          *puVar4 = 0;
        }
        else {
          FUN_00407df0();
          *(undefined4 *)(*(int *)(param_1 + 0x38) + 4) = 0;
          **(undefined4 **)(param_1 + 0x38) = 0;
        }
        FUN_00407df0(*(undefined4 *)(param_1 + 0x38));
        *(undefined4 *)(param_1 + 0x38) = 0;
        apupd_import_software_num = apupd_import_software_num + -1;
        if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                 "apupd_update_wtp_last_image_response_handle",0x1861,apupd_import_software_num);
        }
      }
    }
  }
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_reset_request_send\r\n",
           "apupd_update_wtp_last_image_response_handle",0x1865);
  }
  iVar1 = FUN_00650298(iVar10 + 0x2e,puVar9);
  if (iVar1 != -1) {
    memset(acStack_140,0,0x80);
    uVar3 = *(uint *)(puVar9 + 4);
    sprintf(acStack_140,"%d.%d.%d Build %02d%02d%02d Rel.%05d",(uint)*puVar9,(uint)puVar9[1],
            (uint)puVar9[2],uVar3 >> 0x10,(uVar3 << 0x10) >> 0x18,uVar3 & 0xff,
            *(undefined4 *)(puVar9 + 6));
    memset(acStack_1c0,0,0x80);
    sprintf(acStack_1c0,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar10 + 0x2e),
            (uint)*(byte *)(iVar10 + 0x2f),(uint)*(byte *)(iVar10 + 0x30),
            (uint)*(byte *)(iVar10 + 0x31),(uint)*(byte *)(iVar10 + 0x32),
            (uint)*(byte *)(iVar10 + 0x33));
    memset(auStack_200,0,0x40);
    memset(auStack_c0,0,0x9a);
    FUN_00408190(*(undefined4 *)(iVar10 + 0x18),*(undefined4 *)(iVar10 + 0x1c),
                 *(undefined4 *)(iVar10 + 0x20),*(undefined4 *)(iVar10 + 0x24),
                 *(undefined4 *)(iVar10 + 0x28),auStack_200,0x40,"---");
    uVar7 = apmngr_db_product_type_str(*(undefined1 *)(iVar11 + 0x138));
    uVar8 = FUN_006505b0(iVar10 + 0x2e,auStack_c0);
    pcVar5 = "---";
    if ((*(char *)(iVar11 + 0x138) != '\x01') && (*(char *)(iVar11 + 0x138) != '\x03')) {
      pcVar5 = acStack_140;
    }
    loggerk_reg(0x54,0x3810,1,uVar7,1,uVar8,1,auStack_200,1,acStack_1c0,1,pcVar5,0);
    return 0;
  }
  if (g_apupd_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar5 = "[APUPD_ERROR]%32s() %05d: send reset failed.\r\n";
  uVar7 = 0x1868;
LAB_0065097c:
  printf(pcVar5,"apupd_update_wtp_last_image_response_handle",uVar7);
  return 0xffffffff;
}

