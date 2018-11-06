﻿using System;
using Pitaya;

namespace PitayaCSharpExample
{
  class Example
  {
    static void Main(string[] args)
    {
      Logger.SetLevel(LogLevel.DEBUG);

      Console.WriteLine("c# prog running");

      string serverId = System.Guid.NewGuid().ToString();

      var sdConfig = new SDConfig(
        endpoints: "http://127.0.0.1:4001",
        etcdPrefix: "pitaya/",
        heartbeatTTLSec: 60,
        logHeartbeat: true,
        logServerSync: true,
        logServerDetails: false,
        syncServersIntervalSec: 30);

      var sv = new Server(
         serverId,
         "csharp",
         "{\"ip\":\"127.0.0.1\"}",
         "localhost",
         false);

      NatsConfig nc = new NatsConfig("127.0.0.1:4222", 2000, 1000, 3, 100);

      PitayaCluster cluster = null;

      PitayaCluster.AddSignalHandler(() =>
      {
        if (cluster != null)
        {
          cluster.Dispose();
        }
        Environment.Exit(0);
      });

      try
      {
        cluster = new PitayaCluster(sdConfig, nc, sv);
      }
      catch (PitayaException exc)
      {
        Logger.Error("Failed to create cluster: {0}", exc.Message);
        Environment.Exit(1);
      }

      Logger.Info("pitaya lib initialized successfully :)");

      TestRemote tr = new TestRemote();
      cluster.RegisterRemote(tr);

      System.Threading.Thread.Sleep(1000);

      var res = cluster.Rpc<Protos.RPCRes>(Route.FromString("csharp.testremote.remote"), null);

      Console.WriteLine($"Code: {res.Code}");
      Console.WriteLine($"Msg: {res.Msg}");

      Console.ReadKey();
      //
      //      Server sv = PitayaCluster.GetServer(serverId);
      //      Logger.Info("got server with id: {0}", sv.id);
      //
      //      Protos.RPCMsg msg = new Protos.RPCMsg();
      //      msg.Msg = "hellow from bla";
      //
      //      try
      //      {
      //        Protos.RPCRes res = PitayaCluster.RPC<Protos.RPCRes>(Pitaya.Route.fromString("connector.testremote.test"), msg);
      //        Logger.Info("received rpc res {0}", res);
      //      }
      //      catch (Exception e)
      //      {
      //        Logger.Error("deu ruim: {0}", e);
      //      }
      //
      //      Console.ReadKey();
      // PitayaCluster.Shutdown();
      //    }
      //  }
    }
  }
}