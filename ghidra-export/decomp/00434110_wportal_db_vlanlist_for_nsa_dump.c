// func wportal_db_vlanlist_for_nsa_dump @ 00434110 size=900

void wportal_db_vlanlist_for_nsa_dump(void)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar7 = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  puts("Vlan list for nsa:");
  FUN_004082d0(wportal_nsa_mutex,0xffffffff);
  do {
    iVar1 = FUN_004081b0(vlan_list_array_for_nsa + iVar7 * 0xc);
    if (iVar1 != 0) {
      printf(" VLAN %d: \n",iVar7);
      for (; iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        if (iVar1 != 0x110) {
          uVar4 = *(undefined4 *)(iVar1 + 0x18);
          uVar5 = (uint)*(byte *)(iVar1 + -0x9c);
          uVar6 = (uint)*(byte *)(iVar1 + -0x9b);
          uVar2 = (uint)*(byte *)(iVar1 + -0x9a);
          if (*(char *)(iVar1 + 0x56) == '\0') {
            if (*(char *)(iVar1 + 0x40) == '\x02') {
              printf("   nsaEntry: vlan %d, mac: %02x:%02x:%02x:%02x:%02x:%02x, authType: %d, username: %s, passwd: %s, cmcc server: %x:%x:%x:%x:%x:%x:%x:%x\n"
                     ,uVar4,uVar5,uVar6,uVar2,(uint)*(byte *)(iVar1 + -0x99),
                     (uint)*(byte *)(iVar1 + -0x98),(uint)*(byte *)(iVar1 + -0x97),
                     *(undefined4 *)(iVar1 + 0x38),iVar1 + -0x96,iVar1 + -0x104,
                     (uint)*(ushort *)(iVar1 + 0x44),(uint)*(ushort *)(iVar1 + 0x46),
                     (uint)*(ushort *)(iVar1 + 0x48),(uint)*(ushort *)(iVar1 + 0x4a),
                     (uint)*(ushort *)(iVar1 + 0x4c),(uint)*(ushort *)(iVar1 + 0x4e),
                     (uint)*(ushort *)(iVar1 + 0x50),(uint)*(ushort *)(iVar1 + 0x52));
            }
            else {
              printf("   nsaEntry: vlan %d, mac: %02x:%02x:%02x:%02x:%02x:%02x, authType: %d, username: %s, passwd: %s, cmcc server: %x\n"
                     ,uVar4,uVar5,uVar6,uVar2,(uint)*(byte *)(iVar1 + -0x99),
                     (uint)*(byte *)(iVar1 + -0x98),(uint)*(byte *)(iVar1 + -0x97),
                     *(undefined4 *)(iVar1 + 0x38),iVar1 + -0x96,iVar1 + -0x104,
                     *(undefined4 *)(iVar1 + 0x44));
            }
          }
          else {
            if (*(char *)(iVar1 + 0x40) == '\x02') {
              printf("   nsaEntry: vlan %d, mac: %02x:%02x:%02x:%02x:%02x:%02x, authType: %d, username: %s, cmcc server: %x:%x:%x:%x:%x:%x:%x:%x\n"
                     ,uVar4,uVar5,uVar6,uVar2,(uint)*(byte *)(iVar1 + -0x99),
                     (uint)*(byte *)(iVar1 + -0x98),(uint)*(byte *)(iVar1 + -0x97),
                     *(undefined4 *)(iVar1 + 0x38),iVar1 + -0x96,(uint)*(ushort *)(iVar1 + 0x44),
                     (uint)*(ushort *)(iVar1 + 0x46),(uint)*(ushort *)(iVar1 + 0x48),
                     (uint)*(ushort *)(iVar1 + 0x4a),(uint)*(ushort *)(iVar1 + 0x4c),
                     (uint)*(ushort *)(iVar1 + 0x4e),(uint)*(ushort *)(iVar1 + 0x50),
                     (uint)*(ushort *)(iVar1 + 0x52));
            }
            else {
              printf("   nsaEntry: vlan %d, mac: %02x:%02x:%02x:%02x:%02x:%02x, authType: %d, username: %s, cmcc server: %x\n"
                     ,uVar4,uVar5,uVar6,uVar2,(uint)*(byte *)(iVar1 + -0x99),
                     (uint)*(byte *)(iVar1 + -0x98),(uint)*(byte *)(iVar1 + -0x97),
                     *(undefined4 *)(iVar1 + 0x38),iVar1 + -0x96,*(undefined4 *)(iVar1 + 0x44));
            }
            memcpy(&local_38,(void *)(iVar1 + -0x104),4);
            iVar7 = 0;
            memcpy(&local_34,(void *)(iVar1 + -0x100),4);
            memcpy(&local_30,(void *)(iVar1 + -0xfc),4);
            memcpy(&local_2c,(void *)(iVar1 + -0xf8),4);
            printf("challenge: ");
            pbVar3 = (byte *)&local_38;
            do {
              iVar7 = iVar7 + 1;
              printf("%02x ",(uint)*pbVar3);
              pbVar3 = (byte *)((int)&local_38 + iVar7);
            } while (iVar7 != 0x10);
            iVar7 = 0;
            printf(", ");
            memcpy(&local_38,(void *)(iVar1 + -0xf4),4);
            memcpy(&local_34,(void *)(iVar1 + -0xf0),4);
            memcpy(&local_30,(void *)(iVar1 + -0xec),4);
            memcpy(&local_2c,(void *)(iVar1 + -0xe8),4);
            printf("chapPassword: ");
            pbVar3 = (byte *)&local_38;
            do {
              iVar7 = iVar7 + 1;
              printf("%02x ",(uint)*pbVar3);
              pbVar3 = (byte *)((int)&local_38 + iVar7);
            } while (iVar7 != 0x10);
            printf(", ");
            printf("chapid: %x\n",(uint)*(byte *)(iVar1 + -0xe4));
            iVar7 = 0x10;
          }
        }
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x1000);
  FUN_00407f30(wportal_nsa_mutex);
  putchar(10);
  return;
}

