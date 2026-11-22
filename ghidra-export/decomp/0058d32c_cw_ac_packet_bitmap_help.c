// func cw_ac_packet_bitmap_help @ 0058d32c size=232

void cw_ac_packet_bitmap_help(void)

{
  puts("Bitmap-Packet Corresponding table(starting from 0):");
  puts("\t0/1:\tdiscovery request/response.");
  puts("\t2/3:\tjoin request/response.");
  puts("\t4/5:\tconfigure status request/response.");
  puts("\t6/7:\tconfigure update request/response.");
  puts("\t8/9:\twtp event request/response.");
  puts("\t10/11:\tchange state event request/response.");
  puts("\t12/13:\techo request/response.");
  puts("\t14/15:\timage data request/response.");
  puts("\t16/17:\treset request/response.");
  puts("\t18/19:\tprimary discovery request/response.");
  puts("\t20/21:\tdata transfer request/response.");
  puts("\t22/23:\tclear configuration request/response.");
  puts("\t24/25:\tstation configuration request/response.");
  puts("\t26/27:\tIEEE 802.11 WLAN configuration request/response.");
  puts("\nFor example,if you want to see the configure update request/response(6/7) and ");
  puts("IEEE 802.11 WLAN configuration request/response(26/27) packet, you need to set ");
  puts("capwap_packet_bitmap to 00001100000000000000000011000000(0x0c0000c0).");
  return;
}

