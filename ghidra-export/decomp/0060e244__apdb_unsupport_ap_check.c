// func _apdb_unsupport_ap_check @ 0060e244 size=720

void _apdb_unsupport_ap_check(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_v1;
  undefined4 extraout_v1_00;
  char *__s1;
  int iVar3;
  int iVar4;
  char local_a0 [12];
  char local_94 [12];
  int local_88;
  int local_84;
  undefined4 local_80;
  void *local_7c;
  char acStack_78 [72];
  int local_30;
  
  do {
    sleep(300);
    FUN_004082d0(apdb_pkt_mutex,0xffffffff);
    FUN_00407e70();
    if (((unrecognize_ap != 0) && (unrecognize_ap_lastest_time < extraout_v1)) &&
       (299 < extraout_v1 - unrecognize_ap_lastest_time)) {
      unrecognize_ap_lastest_time = 0;
      unrecognize_ap = 0;
    }
    local_94[0] = '\0';
    local_94[1] = '\0';
    local_94[2] = '\0';
    local_94[3] = '\0';
    local_94[4] = '\0';
    local_94[5] = '\0';
    local_94[6] = '\0';
    local_94[7] = '\0';
    local_94[8] = '\0';
    local_94[9] = '\0';
    local_94[10] = 0;
    local_a0[0] = '\0';
    local_a0[1] = '\0';
    local_a0[2] = '\0';
    local_a0[3] = '\0';
    local_a0[4] = '\0';
    local_a0[5] = '\0';
    local_a0[6] = '\0';
    local_a0[7] = '\0';
    local_a0[8] = '\0';
    local_a0[9] = '\0';
    local_a0[10] = 0;
    memset(acStack_78,0,0x41);
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = (void *)0x0;
    if (unsupport_ap_root != 0) {
      local_84 = 100;
      FUN_00407e70();
      local_80 = extraout_v1_00;
      local_7c = (void *)FUN_00408450(local_84 << 2,0xa5);
      if (local_7c != (void *)0x0) {
        iVar4 = 0;
        memset(local_7c,0,local_84 << 2);
        FUN_00408570(unsupport_hash,_apdb_expired_unsupport_ap_collect,&local_88);
LAB_0060e374:
        if (iVar4 < local_88) {
          __s1 = *(char **)((int)local_7c + iVar4 * 4);
          if (__s1 == (char *)0x0) {
            iVar4 = iVar4 + 1;
          }
          else {
            iVar3 = 0;
            local_30 = cJSON_GetArraySize(unsupport_ap_root);
            while (iVar3 < local_30) {
              uVar1 = cJSON_GetArrayItem(unsupport_ap_root,iVar3);
              iVar2 = cJSON_GetObjectItem(uVar1,"model_name");
              if ((iVar2 == 0) || (*(int *)(iVar2 + 0xc) != 4)) {
                iVar3 = iVar3 + 1;
              }
              else {
                strncpy(acStack_78,*(char **)(iVar2 + 0x10),0x40);
                iVar2 = strcmp(__s1,acStack_78);
                if (iVar2 == 0) {
                  sprintf(local_94,"%d.%d",(int)*(short *)(__s1 + 0x42),(int)*(short *)(__s1 + 0x44)
                         );
                  iVar2 = cJSON_GetObjectItem(uVar1,"hardware_ver");
                  if (iVar2 == 0) {
                    iVar3 = iVar3 + 1;
                  }
                  else if (*(int *)(iVar2 + 0xc) == 4) {
                    strncpy(local_a0,*(char **)(iVar2 + 0x10),10);
                    iVar2 = strcmp(local_a0,local_94);
                    if (iVar2 == 0) {
                      cJSON_DeleteItemFromArray(unsupport_ap_root,iVar3);
                      FUN_00407f40(unsupport_hash,__s1);
                      FUN_00407df0(__s1);
                      iVar4 = iVar4 + 1;
                      goto LAB_0060e374;
                    }
                    iVar3 = iVar3 + 1;
                  }
                  else {
                    iVar3 = iVar3 + 1;
                  }
                }
                else {
                  iVar3 = iVar3 + 1;
                }
              }
            }
            iVar4 = iVar4 + 1;
          }
          goto LAB_0060e374;
        }
        FUN_00407df0();
      }
    }
    iVar4 = FUN_00407ed0(unsupport_hash);
    if (((iVar4 == 0) && (unknown_ap_flag != 0)) && (unrecognize_ap == 0)) {
      unknown_ap_flag = 0;
      iVar4 = access("/tmp/unknown_ap_flag",0);
      if (iVar4 == 0) {
        remove("/tmp/unknown_ap_flag");
      }
    }
    FUN_00407f30(apdb_pkt_mutex);
  } while( true );
}

