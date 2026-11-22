// func _wportal_db_dm_calling_station_hash_print @ 0042b08c size=104

void _wportal_db_dm_calling_station_hash_print(int param_1)

{
  if (param_1 != 0) {
    printf("   autEntry: vlan %d, calling station: %02x:%02x:%02x:%02x:%02x:%02x, auth_type: %d, IP: %s, expire: %d\n"
           ,*(undefined4 *)(param_1 + 0x14),(uint)*(byte *)(param_1 + 0xc),
           (uint)*(byte *)(param_1 + 0xd),(uint)*(byte *)(param_1 + 0xe),
           (uint)*(byte *)(param_1 + 0xf),(uint)*(byte *)(param_1 + 0x10),
           (uint)*(byte *)(param_1 + 0x11),(uint)*(byte *)(param_1 + 0x80),param_1 + 0x58,
           *(undefined4 *)(param_1 + 0x3c));
  }
  return;
}

