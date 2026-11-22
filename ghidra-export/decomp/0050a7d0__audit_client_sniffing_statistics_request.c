// func _audit_client_sniffing_statistics_request @ 0050a7d0 size=744

undefined4 _audit_client_sniffing_statistics_request(int *param_1,undefined4 param_2,void *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  void *__s;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_518 [8];
  undefined1 local_510;
  undefined1 local_50f;
  undefined1 local_50e;
  undefined1 local_50d;
  undefined1 local_50c;
  undefined1 local_50b;
  undefined1 auStack_508 [304];
  undefined1 auStack_3d8 [216];
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  
  iVar8 = 0;
  memset(auStack_300,0,0x2d8);
  memset(auStack_508,0,0x205);
  uVar2 = time((time_t *)0x0);
  local_510 = 0;
  local_50f = 0;
  local_50e = 0;
  local_50d = 0;
  local_50c = 0;
  local_50b = 0;
  memcpy(auStack_518,&DAT_006bcb20,6);
  iVar3 = apmngr_db_entry_get_by_mac(param_3,auStack_300);
  if (iVar3 == 0) {
    while (uVar5 = 0, iVar8 < *param_1) {
      iVar6 = iVar8 * 0x14;
      iVar7 = param_1[1] + iVar6;
      iVar3 = memcmp((void *)(iVar7 + 2),&local_510,6);
      if (iVar3 == 0) {
        iVar8 = iVar8 + 1;
      }
      else {
        iVar3 = memcmp((void *)(iVar7 + 2),auStack_518,6);
        if (iVar3 == 0) {
          iVar8 = iVar8 + 1;
        }
        else if (*(char *)(iVar7 + 0x10) < '\x01') {
          if (*(char *)(iVar7 + 0x10) < -100) {
            iVar8 = iVar8 + 1;
          }
          else if (uVar2 < *(uint *)(iVar7 + 0xc)) {
            iVar8 = iVar8 + 1;
          }
          else if ((byte)(*(char *)(iVar7 + 8) - 1U) < 2) {
            __s = (void *)FUN_00408450(0x4c,0x5e);
            if (__s == (void *)0x0) {
              if (audit_err_switch == 0) {
                return 0xffffffff;
              }
              __format = "[AUDIT_ERR]%s()/%d Memory is not enough.\n";
              uVar4 = 0x61;
              goto LAB_0050aa14;
            }
            memset(__s,0,0x4c);
            cVar1 = *(char *)(param_1[1] + iVar6 + 8);
            *(char *)((int)__s + 6) = cVar1;
            if (cVar1 == '\x02') {
              uVar5 = rdmngr_db_generate_rd_id(local_2f0,*(undefined1 *)(param_1[1] + iVar6));
              iVar3 = wserv_db_rd_get_wserv_id(uVar5,*(undefined1 *)(param_1[1] + iVar6 + 1));
              if (iVar3 != -1) {
                iVar3 = wserv_db_get_entry_by_id(iVar3,auStack_508);
                if (iVar3 == 0) {
                  snprintf((char *)((int)__s + 0x16),0x33,"%s",auStack_3d8);
                  iVar3 = param_1[1];
                  goto LAB_0050a99c;
                }
              }
              FUN_00407df0(__s);
              iVar8 = iVar8 + 1;
            }
            else {
              iVar3 = param_1[1];
LAB_0050a99c:
              memcpy(__s,(void *)(iVar3 + iVar6 + 2),6);
              memcpy((void *)((int)__s + 0x10),param_3,6);
              *(int *)((int)__s + 0xc) = (int)*(char *)(param_1[1] + iVar6 + 0x10);
              *(uint *)((int)__s + 8) = uVar2 - *(int *)(param_1[1] + iVar6 + 0xc);
              audit_client_db_msg_send(2,__s,2,audit_client_db_msg_data_free);
              iVar8 = iVar8 + 1;
            }
          }
          else {
            iVar8 = iVar8 + 1;
          }
        }
        else {
          iVar8 = iVar8 + 1;
        }
      }
    }
  }
  else {
    uVar5 = 0xffffffff;
    if (audit_warn_switch != 0) {
      __format = "[AUDIT_INFO]%s()/%d apmngr_db_entry_get_by_mac() fail.\n";
      uVar4 = 0x51;
LAB_0050aa14:
      uVar5 = 0xffffffff;
      printf(__format,"_audit_client_sniffing_statistics_request",uVar4);
    }
  }
  return uVar5;
}

