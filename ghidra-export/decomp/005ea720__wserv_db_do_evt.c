// func _wserv_db_do_evt @ 005ea720 size=572

int _wserv_db_do_evt(int param_1,code *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *__format;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar8 = 0;
  if (param_1 != 0) {
    uVar6 = param_3;
    iVar2 = FUN_004081b0();
    while (iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      if (param_2 != (code *)0x0) {
        if ((*(int *)(iVar2 + 0xc) == 0) ||
           (iVar4 = rdmngr_db_get_rd_status(*(undefined4 *)(iVar2 + 0x10)), iVar4 != 0)) {
          uVar6 = param_3;
          iVar8 = (*param_2)(iVar2 + 0x10,iVar2 + 0x1a);
          if (((iVar8 != 0) && (g_wserv_warning != 0)) && (iVar4 = is_target_debug_ap(), iVar4 != 0)
             ) {
            uVar5 = (uint)*(byte *)(iVar2 + 0x14);
            uVar6 = 0x6e7;
            uVar7 = *(undefined4 *)(iVar2 + 0x10);
            __format = "<wserv>[warning]%s(): %d  -> do cb for rd_id[%d] wlan_id[%d] fail.\r\n";
LAB_005ea8fc:
            printf(__format,"_wserv_db_do_evt",uVar6,uVar7,uVar5);
          }
        }
        else {
          uVar6 = param_3;
          if ((g_wserv_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            uVar5 = *(uint *)(iVar2 + 0xc);
            uVar7 = *(undefined4 *)(iVar2 + 0x10);
            __format = "<wserv>[warning]%s(): %d  -> rd_id[%d] is disable or evt_mask[%d] is 0.\r\n"
            ;
            uVar6 = 0x6ec;
            goto LAB_005ea8fc;
          }
        }
      }
      iVar4 = 6;
      do {
        uVar5 = *(uint *)(iVar2 + 0xc);
        if ((uVar5 & 1) == 0) {
          if ((uVar5 & 2) == 0) {
            if ((uVar5 & 4) == 0) {
              if ((uVar5 & 8) != 0) {
                uVar6 = (uint)*(byte *)(iVar2 + 0x14);
                _wserv_do_status_event(3,*(undefined4 *)(iVar2 + 0x10),uVar6);
                *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffff7;
              }
            }
            else {
              uVar6 = (uint)*(byte *)(iVar2 + 0x14);
              _wserv_do_status_event(2,*(undefined4 *)(iVar2 + 0x10),uVar6);
              *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffb;
            }
          }
          else {
            uVar5 = iVar2 + 0x9aU & 3;
            uVar1 = iVar2 + 0x9dU & 3;
            uVar6 = (*(int *)((iVar2 + 0x9aU) - uVar5) << uVar5 * 8 |
                    uVar6 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar1 + 1) * 8 |
                    *(uint *)((iVar2 + 0x9dU) - uVar1) >> (3 - uVar1) * 8;
            _wserv_do_bind_event
                      (1,*(undefined4 *)(iVar2 + 0x10),uVar6,*(undefined2 *)(iVar2 + 0x18));
            *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffd;
          }
        }
        else {
          uVar6 = *(uint *)(iVar2 + 0x9a);
          _wserv_do_bind_event(0,*(undefined4 *)(iVar2 + 0x10),uVar6,*(undefined2 *)(iVar2 + 0x18));
          *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      FUN_00407df0(iVar2);
      iVar2 = iVar3;
    }
  }
  return iVar8;
}

