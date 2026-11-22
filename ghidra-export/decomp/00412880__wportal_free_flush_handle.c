// func _wportal_free_flush_handle @ 00412880 size=424

undefined4 _wportal_free_flush_handle(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined1 auStack_188 [128];
  undefined1 auStack_108 [180];
  int local_54;
  int local_2c;
  
  if (g_portal_auth_mode == 1) {
    iVar2 = 1;
    do {
      memset(auStack_188,0,0x16c);
      wportal_db_rdt_get_by_vlan(iVar2,auStack_188);
      if (local_54 != 0) {
        piVar4 = (int *)_wportal_url_parser(auStack_108);
        if (local_2c == 0x40) {
          if (piVar4 != (int *)0x0) {
            if (*piVar4 != 2) goto LAB_00412a18;
            FUN_00407df0();
            iVar3 = _wportal_wserv_add_or_del_old_ftt(param_1);
            if (iVar3 == 0) {
              return 0;
            }
          }
        }
        else if (piVar4 != (int *)0x0) {
LAB_00412a18:
          FUN_00407df0();
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x1000);
  }
  else {
    uVar5 = 0;
    if (g_portal_auth_mode == 0) {
      while (uVar1 = wserv_profile_get_max_wservice(), uVar5 < uVar1) {
        memset(auStack_188,0,0x16c);
        iVar2 = wportal_db_ssid_rdt_get(uVar5,auStack_188);
        if (iVar2 == 0) {
          piVar4 = (int *)_wportal_url_parser(auStack_108);
          if (local_2c == 0x40) {
            if (piVar4 == (int *)0x0) {
              uVar5 = uVar5 + 1;
            }
            else {
              if (*piVar4 != 2) goto LAB_00412970;
              FUN_00407df0();
              iVar2 = _wportal_wserv_add_or_del_old_ftt(param_1);
              if (iVar2 == 0) {
                return 0;
              }
              uVar5 = uVar5 + 1;
            }
          }
          else if (piVar4 == (int *)0x0) {
            uVar5 = uVar5 + 1;
          }
          else {
LAB_00412970:
            uVar5 = uVar5 + 1;
            FUN_00407df0();
          }
        }
        else {
          uVar5 = uVar5 + 1;
        }
      }
    }
  }
  return 0;
}

