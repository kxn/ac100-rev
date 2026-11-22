// func _wportal_db_nsa_copy @ 0042b67c size=236

void _wportal_db_nsa_copy(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    memcpy((void *)(param_1 + 0x74),(void *)(param_2 + 0x74),6);
    memcpy((void *)(param_1 + 0x128),(void *)(param_2 + 0x128),0x20);
    *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_2 + 0x148);
    *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_2 + 0x14c);
    memcpy((void *)(param_1 + 0x108),(void *)(param_2 + 0x108),8);
    memcpy((void *)(param_1 + 0x7a),(void *)(param_2 + 0x7a),0x65);
    memcpy((void *)(param_1 + 0xc),(void *)(param_2 + 0xc),0x65);
    memcpy((void *)(param_1 + 0xdf),(void *)(param_2 + 0xdf),0x29);
    memcpy((void *)(param_1 + 0xc),(void *)(param_2 + 0xc),0x68);
    *(undefined1 *)(param_1 + 0x166) = *(undefined1 *)(param_2 + 0x166);
    memcpy((void *)(param_1 + 0x150),(void *)(param_2 + 0x150),0x14);
    *(undefined2 *)(param_1 + 0x164) = *(undefined2 *)(param_2 + 0x164);
  }
  return;
}

