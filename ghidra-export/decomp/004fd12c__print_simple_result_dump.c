// func _print_simple_result_dump @ 004fd12c size=240

void _print_simple_result_dump(int param_1)

{
  if (param_1 != 0) {
    printf("                test_type=%d\n",(uint)*(byte *)(param_1 + 0x32));
    printf("                serindex=%d\n",(uint)*(ushort *)(param_1 + 0x30));
    printf("                start_time=%d\n",*(undefined4 *)(param_1 + 0x2c));
    printf("                total_time=%d\n",*(undefined4 *)(param_1 + 0xc));
    printf("                fail_reason=%d\n",*(undefined4 *)(param_1 + 0x10));
    printf("                fail_stage=%d\n",(uint)*(byte *)(param_1 + 0x24));
    printf("                txRate=%d\n",(uint)*(ushort *)(param_1 + 0x14));
    printf("                rxRate=%d\n",(uint)*(ushort *)(param_1 + 0x16));
    printf("                txCount=%d\n",(uint)*(ushort *)(param_1 + 0x18));
    printf("                retryCount=%d\n",(uint)*(ushort *)(param_1 + 0x1a));
    printf("                rssi=%d\n",(int)*(char *)(param_1 + 0x25));
    printf("                snr=%d\n",(int)*(short *)(param_1 + 0x1c));
    return;
  }
  return;
}

