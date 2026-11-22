// func _dhcpdef_db_apbind_entry_print @ 00466b38 size=644

void _dhcpdef_db_apbind_entry_print(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *__s;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  if (param_1 == (int *)0x0) {
    if ((g_dhcpdef_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "_dhcpdef_db_apbind_entry_print",0x4df,"entry");
    }
    return;
  }
  puts("######################################\r");
  printf("  ap_id                = %d\r\n",*param_1);
  printf("  is_firm              = %d\r\n",param_1[1]);
  printf("  enable               = %d\r\n",(int)*(char *)(param_1 + 2));
  printf("  num of bind servers  = %d\r\n",*(undefined4 *)((int)param_1 + 9));
  uVar7 = 0;
  if (*(int *)((int)param_1 + 0xd) != 0) {
    printf("  server lists: (");
LAB_00466bec:
    do {
      iVar6 = DAT_007670a8;
      if (DAT_0076708c <= uVar7) goto LAB_00466cfc;
      iVar5 = *param_1;
      if (49999 < iVar5) {
        iVar3 = apmngr_db_get_ap_max();
        iVar8 = apmngr_db_get_template_max();
        iVar5 = iVar5 + -50000 + iVar3 + iVar8;
      }
      iVar3 = DAT_007670a8;
      iVar8 = uVar7 * 4;
      if (-1 < *(int *)(*(int *)(iVar6 + iVar5 * 0x11 + 0xd) + iVar8)) {
        iVar6 = *param_1;
        if (49999 < iVar6) {
          iVar5 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar6 = iVar6 + -50000 + iVar5 + iVar4;
        }
        if (*(uint *)(*(int *)(iVar3 + iVar6 * 0x11 + 0xd) + iVar8) < l_dhcpdef_profile) {
          uVar1 = (int)param_1 + 0xdU & 3;
          uVar7 = uVar7 + 1;
          uVar2 = (uint)(param_1 + 4) & 3;
          printf("%d,",*(undefined4 *)
                        (((*(int *)(((int)param_1 + 0xdU) - uVar1) << uVar1 * 8 |
                          l_dhcpdef_profile & 0xffffffffU >> (4 - uVar1) * 8) &
                          -1 << (uVar2 + 1) * 8 |
                         *(uint *)((int)(param_1 + 4) - uVar2) >> (3 - uVar2) * 8) + iVar8));
          goto LAB_00466bec;
        }
      }
      uVar7 = uVar7 + 1;
    } while( true );
  }
  __s = "  server lists: N/A\r";
LAB_00466d00:
  puts(__s);
  return;
LAB_00466cfc:
  __s = ")\r";
  goto LAB_00466d00;
}

