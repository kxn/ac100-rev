// @category ACAP
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.nio.file.*;
import java.util.regex.Pattern;

public class ExportTargets extends GhidraScript {
 public void run() throws Exception {
  String[] args=getScriptArgs(); Path out=Paths.get(args[1]);Files.createDirectories(out);
  Pattern wanted=Pattern.compile(args[2]);
  DecompInterface decompiler=new DecompInterface();decompiler.openProgram(currentProgram);
  for(String line:Files.readAllLines(Paths.get(args[0]))) {
   String[] parts=line.trim().split("\\s+",4);
   if(parts.length!=4 || !wanted.matcher(parts[3]).find())continue;
   Address at=toAddr(Long.parseUnsignedLong(parts[0],16));
   Function f=getFunctionAt(at);
   if(f==null){disassemble(at);f=createFunction(at,parts[3]);}
   if(f==null){println("MISSING "+parts[3]);continue;}
   DecompileResults result=decompiler.decompileFunction(f,45,monitor);
   String c="// V6 "+parts[3]+" @"+parts[0]+" size="+parts[1]+"\n";
   c+=result.decompileCompleted()?result.getDecompiledFunction().getC():"// FAILED "+result.getErrorMessage();
   Files.writeString(out.resolve(parts[0]+"_"+parts[3].replaceAll("[^A-Za-z0-9_$._]","_")+".c"),c);
   println("EXPORTED "+parts[3]);
  }
  decompiler.dispose();
 }
}
