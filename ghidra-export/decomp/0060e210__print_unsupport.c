// func _print_unsupport @ 0060e210 size=1

void _print_unsupport(int param_1)

{
  printf("%s %d.%d %d\n\r",param_1,(int)*(short *)(param_1 + 0x42),(int)*(short *)(param_1 + 0x44),
         *(undefined4 *)(param_1 + 0x48));
  return;
}

