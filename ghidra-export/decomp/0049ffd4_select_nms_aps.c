// func select_nms_aps @ 0049ffd4 size=1

void select_nms_aps(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_300 [20];
  int iStack_2ec;
  int iStack_2c4;
  undefined1 auStack_2b8 [381];
  char cStack_13b;
  uint uStack_ac;
  
  memset(auStack_300,0,0x2d8);
  iVar1 = apmngr_db_get_ap_max();
  do {
    do {
      do {
        sleep(600);
        iVar2 = cloud_mngt_nms_spupport_ap_cnt(0);
      } while (g_nms_aps_support_cnt <= iVar2);
      iVar2 = apmngr_db_active_ap_num_get();
      iVar3 = cloud_mngt_nms_spupport_ap_cnt(0);
    } while (iVar2 <= iVar3);
    uVar4 = 0;
    while (((int)uVar4 < iVar1 &&
           (iVar2 = cloud_mngt_nms_spupport_ap_cnt(0), iVar2 < g_nms_aps_support_cnt))) {
      iVar2 = apmngr_db_active_ap_num_get();
      iVar3 = cloud_mngt_nms_spupport_ap_cnt(0);
      if (iVar2 <= iVar3) break;
      memset(auStack_300,0,0x2d8);
      iVar2 = apmngr_db_entry_get_by_id(uVar4 & 0xffff,auStack_300);
      if ((iVar2 == -1) || ((uStack_ac & 0x20000) == 0)) {
        uVar4 = uVar4 + 1;
      }
      else {
        iVar2 = multi_link_status_get(uVar4 & 0xffff);
        if (iVar2 == 1) {
          if (iStack_2c4 == 0) {
            uVar4 = uVar4 + 1;
          }
          else if (iStack_2ec == 7) {
            uVar4 = uVar4 + 1;
          }
          else {
            iVar2 = set_cloud_mngt_ap_nms_spupport(uVar4,0);
            if (iVar2 == 0) {
              uVar4 = uVar4 + 1;
              if (cStack_13b != '\0') {
                FUN_0049ff74(auStack_2b8);
              }
            }
            else {
              uVar4 = uVar4 + 1;
            }
          }
        }
        else {
          uVar4 = uVar4 + 1;
        }
      }
    }
  } while( true );
}

