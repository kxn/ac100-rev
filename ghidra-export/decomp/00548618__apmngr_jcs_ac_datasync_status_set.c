// func _apmngr_jcs_ac_datasync_status_set @ 00548618 size=436

void _apmngr_jcs_ac_datasync_status_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__s2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  iVar1 = json_object_object_get(param_1,"status");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    iVar5 = 0;
    if (iVar2 == 6) {
      do {
        while( true ) {
          if (datasync_status_map <= iVar5) {
            if (jcs_err_switch == 0) goto LAB_00548674;
            pcVar4 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_00548740;
          }
          iVar2 = iVar5 * 0x10;
          pcVar4 = *(char **)(PTR__mt_datasync_status_00731f84 + iVar2);
          if (pcVar4 != (char *)0x0) break;
          iVar5 = iVar5 + 1;
        }
        __s2 = (char *)json_object_get_string(iVar1);
        iVar3 = strcmp(pcVar4,__s2);
        iVar5 = iVar5 + 1;
      } while (iVar3 != 0);
      ac_datasync_status = *(int *)(PTR__mt_datasync_status_00731f84 + iVar2 + 0xc);
      goto LAB_00548684;
    }
    if (jcs_err_switch != 0) {
      pcVar4 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00548740:
      printf(pcVar4,"_apmngr_jcs_ac_datasync_status_set",0x9e3);
    }
  }
LAB_00548674:
  if (jcs_err_switch == 0) {
    ac_datasync_status = -1;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
           "_apmngr_jcs_ac_datasync_status_set",0x9e3);
    ac_datasync_status = -1;
  }
LAB_00548684:
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d set ac_datasync_status = %d\n",
           "_apmngr_jcs_ac_datasync_status_set",0x9e4,ac_datasync_status);
  }
  if (ac_datasync_status == 0) {
    apmngr_db_datasync_id_allocator_get();
    return;
  }
  return;
}

