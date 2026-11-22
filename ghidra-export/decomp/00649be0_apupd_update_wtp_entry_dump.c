// func apupd_update_wtp_entry_dump @ 00649be0 size=104

void apupd_update_wtp_entry_dump(int param_1)

{
  puts("=========>update wtp dump:");
  printf("mac: %02x:%02x:%02x:%02x:%02x:%02x\n",(uint)*(byte *)(param_1 + 0x18),
         (uint)*(byte *)(param_1 + 0x19),(uint)*(byte *)(param_1 + 0x1a),
         (uint)*(byte *)(param_1 + 0x1b),(uint)*(byte *)(param_1 + 0x1c),
         (uint)*(byte *)(param_1 + 0x1d));
  printf("state: %d\n",*(undefined4 *)(param_1 + 0x20));
  return;
}

