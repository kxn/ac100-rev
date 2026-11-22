// func apupd_db_send_sub_image_info_to_update_wtp @ 00659944 size=1420

undefined4 apupd_db_send_sub_image_info_to_update_wtp(undefined4 param_1)

{
  undefined1 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *__dest;
  char *__format;
  undefined4 uVar7;
  int iVar8;
  undefined4 local_res0 [4];
  undefined1 auStack_300 [16];
  ushort local_2f0;
  
  local_res0[0] = param_1;
  memset(auStack_300,0,0x2d8);
  if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_db_send_sub_image_info_to_update_wtp\r\n",
           "apupd_db_send_sub_image_info_to_update_wtp",0x27fd);
  }
  iVar3 = FUN_00407fa0(apupd_update_model_hash,local_res0);
  if (iVar3 == 0) {
    if (g_apupd_debug == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: no find tmp_update_model.\r\n";
    uVar7 = 0x2802;
  }
  else {
    iVar4 = FUN_004081b0(iVar3 + 0x14);
    do {
      while( true ) {
        if (iVar4 == 0) {
          return 0;
        }
        iVar5 = FUN_00408680(iVar4);
        bVar2 = false;
        iVar6 = apmngr_db_entry_get_by_mac(*(int *)(iVar4 + 0x24) + 0x2e,auStack_300);
        if (iVar6 == 0) {
          iVar6 = *(int *)(iVar4 + 0x14);
        }
        else {
          bVar2 = true;
          if (g_apupd_error == 0) {
            iVar6 = *(int *)(iVar4 + 0x14);
          }
          else {
            iVar6 = is_target_debug_ap();
            if (iVar6 == 0) {
              iVar6 = *(int *)(iVar4 + 0x14);
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: get ap_entry by mac[%02X:%02X:%02X:%02X:%02X:%02X] failed.\r\n"
                     ,"apupd_db_send_sub_image_info_to_update_wtp",0x2810,
                     (uint)*(byte *)(iVar4 + 0xc),(uint)*(byte *)(iVar4 + 0xd),
                     (uint)*(byte *)(iVar4 + 0xe),(uint)*(byte *)(iVar4 + 0xf),
                     (uint)*(byte *)(iVar4 + 0x10),(uint)*(byte *)(iVar4 + 0x11));
              iVar6 = *(int *)(iVar4 + 0x14);
            }
          }
        }
        if (iVar6 == 0) {
          iVar6 = *(int *)(iVar4 + 0x18);
        }
        else {
          bVar2 = true;
          if (g_apupd_error == 0) {
            iVar6 = *(int *)(iVar4 + 0x18);
          }
          else {
            iVar6 = is_target_debug_ap();
            if (iVar6 == 0) {
              iVar6 = *(int *)(iVar4 + 0x18);
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: update wtp state(%d) is invalib\r\n",
                     "apupd_db_send_sub_image_info_to_update_wtp",0x2817,
                     *(undefined4 *)(iVar4 + 0x14));
              iVar6 = *(int *)(iVar4 + 0x18);
            }
          }
        }
        if ((iVar6 == 2) || (iVar6 == 8)) break;
        if ((g_apupd_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: update wtp large_image_update_state(%d) is invalib\r\n",
                 "apupd_db_send_sub_image_info_to_update_wtp",0x281d,*(undefined4 *)(iVar4 + 0x18));
        }
LAB_00659a2c:
        if ((g_apupd_debug != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: stop ap[%d] UPGRADE\r\n",
                 "apupd_db_send_sub_image_info_to_update_wtp",0x2823,(uint)local_2f0);
        }
        *(undefined4 *)(iVar4 + 0x14) = 0;
        *(undefined4 *)(iVar4 + 0x18) = 6;
        *(undefined4 *)(*(int *)(iVar4 + 0x24) + 0x48) = 0xb;
        apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
        iVar6 = apupd_update_wtp_entry_delete(iVar4 + -0xc);
        iVar4 = iVar5;
        if (iVar6 == -1) {
          if (g_apupd_error == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          __format = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
          uVar7 = 0x282a;
          goto LAB_00659df8;
        }
      }
      if (bVar2) goto LAB_00659a2c;
      if ((g_apupd_debug != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: notify ap[%d] sub image info\r\n",
               "apupd_db_send_sub_image_info_to_update_wtp",0x2830,(uint)local_2f0);
      }
      *(undefined4 *)(iVar4 + 0x18) = 4;
      *(undefined4 *)(iVar4 + 0x14) = 1;
      iVar6 = *(int *)(iVar3 + 0x10);
      if (*(int *)(iVar6 + 0x7ec) == 1) {
        iVar6 = *(int *)(iVar4 + 0x28);
LAB_00659c00:
        iVar6 = FUN_00407fa0(*(undefined4 *)(iVar6 + 0x2c),*(int *)(iVar4 + 0x24) + 0x58);
        if (iVar6 == 0) {
          if ((g_apupd_error != 0) && (iVar6 = is_target_debug_ap(local_2f0), iVar6 != 0)) {
            printf("[APUPD_ERROR]%32s() %05d: can\'t find wtp_list,according firmware id:\r\n",
                   "apupd_db_send_sub_image_info_to_update_wtp",0x283f);
          }
          iVar8 = 0;
          iVar6 = *(int *)(iVar4 + 0x24);
          while( true ) {
            iVar6 = iVar6 + iVar8;
            iVar8 = iVar8 + 1;
            printf("%02X",(uint)*(byte *)(iVar6 + 0x58));
            if (iVar8 == 0x10) break;
            iVar6 = *(int *)(iVar4 + 0x24);
          }
          putchar(10);
        }
        else {
          iVar6 = apupd_sub_image_info_send
                            (local_2f0,*(undefined1 *)(iVar6 + 400),*(undefined4 *)(iVar6 + 0x44),
                             iVar6 + 0x4c);
          if (((iVar6 == -1) && (g_apupd_error != 0)) && (iVar6 = is_target_debug_ap(6), iVar6 != 0)
             ) {
            uVar7 = 0x283a;
            goto LAB_00659cbc;
          }
        }
      }
      else {
        if (*(int *)(iVar6 + 0x7ec) == 3) {
          if (*(int *)(*(int *)(iVar4 + 0x24) + 0x54) == 1) {
            iVar6 = *(int *)(iVar4 + 0x28);
            goto LAB_00659c00;
          }
          uVar1 = *(undefined1 *)(iVar6 + 0x1a0);
        }
        else {
          uVar1 = *(undefined1 *)(iVar6 + 0x1a0);
        }
        iVar6 = apupd_sub_image_info_send
                          (local_2f0,uVar1,*(undefined4 *)(iVar6 + 0x1ac),iVar6 + 0x1b4);
        if (((iVar6 == -1) && (g_apupd_error != 0)) && (iVar6 = is_target_debug_ap(6), iVar6 != 0))
        {
          uVar7 = 0x284b;
LAB_00659cbc:
          printf("[APUPD_ERROR]%32s() %05d: send to ap(%d) sub image action packet failed.\r\n",
                 "apupd_db_send_sub_image_info_to_update_wtp",uVar7,(uint)local_2f0);
        }
      }
      __dest = (void *)FUN_00408450(6,0x284f);
      if (__dest == (void *)0x0) {
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
        uVar7 = 0x2851;
        goto LAB_00659df8;
      }
      memcpy(__dest,(void *)(iVar4 + 0xc),6);
      if (*(int *)(iVar4 + 0x1c) != -1) {
        FUN_00408060();
        *(undefined4 *)(iVar4 + 0x1c) = 0xffffffff;
      }
      iVar6 = FUN_00408340(0x1e,0,apupd_update_wtp_sub_image_info_timer_callback,__dest,
                           apupd_update_wtp_argv_callback,
                           "apupd_db_send_sub_image_info_to_update_wtp",0x285c);
      *(int *)(iVar4 + 0x1c) = iVar6;
      iVar4 = iVar5;
    } while (iVar6 != -1);
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n";
    uVar7 = 0x285f;
  }
LAB_00659df8:
  printf(__format,"apupd_db_send_sub_image_info_to_update_wtp",uVar7);
  return 0xffffffff;
}

