// @category ACAP
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import java.nio.file.*;
import java.util.HashSet;
public class ExportStringUsers extends GhidraScript {
 public void run() throws Exception {
  String[] args=getScriptArgs();Path out=Paths.get(args[0]);Files.createDirectories(out);
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);HashSet<Function> done=new HashSet<>();
  for(int i=1;i<args.length;i++)for(Reference ref:getReferencesTo(toAddr(Long.parseUnsignedLong(args[i],16)))) {
   Function f=getFunctionContaining(ref.getFromAddress());println("XREF "+args[i]+" "+ref.getFromAddress()+" "+f);
   if(f==null||!done.add(f))continue;
   DecompileResults r=d.decompileFunction(f,45,monitor);
   if(r.decompileCompleted())Files.writeString(out.resolve(f.getEntryPoint()+"_"+f.getName()+".c"),r.getDecompiledFunction().getC());
  }d.dispose();
 }
}
