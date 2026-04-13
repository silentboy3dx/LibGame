#pragma once

#include <LibGraphics/Image.hpp>

#include <unordered_map>
#include <memory>
#include <string>

namespace LibGame::Asset {

    struct AssetType {
        inline static const std::string TYPE_2K = "2K";
        inline static const std::string TYPE_4K = "4K";
    };

    class AssetCache {
    public:
        // Singleton accessor
        static AssetCache& Instance();

        // Load or get from cache
        std::shared_ptr<LibGraphics::Image> Load(const std::string& relativePath);

        // Preload entire preload.json
        void PreloadAll();
        void PrintCache() const;

        std::string getAssetType() const;

        // Cache utilities
        bool Has(const std::string& relativePath) const;
        void Remove(const std::string& relativePath);
        void Clear();



    private:
        AssetCache() = default; // private constructor
        AssetCache(const AssetCache&) = delete;
        AssetCache& operator=(const AssetCache&) = delete;

        static std::string NormalizePath(const std::string& path);
        static std::string BuildFullPath(const std::string& relativePath);

        std::unordered_map<std::string, std::shared_ptr<LibGraphics::Image>> cache;
    };

}
