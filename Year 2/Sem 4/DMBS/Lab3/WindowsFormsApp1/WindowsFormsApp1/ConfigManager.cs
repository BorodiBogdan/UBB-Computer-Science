using System;
using System.Configuration;
using System.Xml;

namespace WindowsFormsApp1
{
    public class ScenarioConfig
    {
        public string Name { get; set; }
        public string DisplayName { get; set; }

        // Master table info
        public string MasterTableName { get; set; }
        public string MasterIdColumn { get; set; }
        public string MasterDisplayColumn { get; set; }
        public string MasterQuery { get; set; }
        public string MasterLabel { get; set; }

        // Detail table info
        public string DetailTableName { get; set; }
        public string DetailIdColumn { get; set; }
        public string DetailForeignKeyColumn { get; set; }
        public string DetailDisplayColumn { get; set; }
        public string DetailQuery { get; set; }
        public string DetailLabel { get; set; }
    }

    public static class ConfigManager
    {
        public static string GetConnectionString()
        {
            return ConfigurationManager.ConnectionStrings["DefaultConnection"].ConnectionString;
        }

        public static ScenarioConfig GetCurrentScenario()
        {
            string currentScenarioName = ConfigurationManager.AppSettings["CurrentScenario"];
            string configPath = ConfigurationManager.AppSettings["ScenarioConfigPath"];

            if (string.IsNullOrEmpty(configPath))
                throw new Exception("ScenarioConfigPath not set in App.config");

            XmlDocument configDoc = new XmlDocument();
            configDoc.Load(configPath);

            XmlNode scenarioNode = configDoc.SelectSingleNode($"//scenarios/scenario[@name='{currentScenarioName}']");

            if (scenarioNode == null)
                throw new Exception($"Scenario '{currentScenarioName}' not found in configuration file.");

            ScenarioConfig config = new ScenarioConfig
            {
                Name = currentScenarioName,
                DisplayName = GetAttributeValue(scenarioNode, "displayName")
            };

            // Parse master
            XmlNode masterNode = scenarioNode.SelectSingleNode("masterTable");
            if (masterNode != null)
            {
                config.MasterTableName = GetAttributeValue(masterNode, "name");
                config.MasterIdColumn = GetAttributeValue(masterNode, "idColumn");
                config.MasterDisplayColumn = GetAttributeValue(masterNode, "displayColumn");
                config.MasterQuery = masterNode.SelectSingleNode("query")?.InnerText.Trim();
            }

            // Parse detail
            XmlNode detailNode = scenarioNode.SelectSingleNode("detailTable");
            if (detailNode != null)
            {
                config.DetailTableName = GetAttributeValue(detailNode, "name");
                config.DetailIdColumn = GetAttributeValue(detailNode, "idColumn");
                config.DetailForeignKeyColumn = GetAttributeValue(detailNode, "foreignKeyColumn");
                config.DetailDisplayColumn = GetAttributeValue(detailNode, "displayColumn");
                config.DetailQuery = detailNode.SelectSingleNode("query")?.InnerText.Trim();
            }

            // Parse labels
            XmlNode labelsNode = scenarioNode.SelectSingleNode("labels");
            if (labelsNode != null)
            {
                config.MasterLabel = labelsNode.SelectSingleNode("masterLabel")?.InnerText.Trim();
                config.DetailLabel = labelsNode.SelectSingleNode("detailLabel")?.InnerText.Trim();
            }

            return config;
        }


        private static string GetAttributeValue(XmlNode node, string attributeName)
        {
            XmlAttribute attribute = node.Attributes[attributeName];
            return attribute?.Value;
        }
    }
}