rec {
  description = "A fractal/aliasing/moire-pattern thingy...";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-22.11";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in rec {
        packages = rec {
          default = rfrakt;

          rfrakt = pkgs.stdenv.mkDerivation {
            pname = "rfrakt";
            version = "0.0.0";
            src = nixpkgs.lib.cleanSource ./.;
            nativeBuildInputs = [
              pkgs.cmake
              pkgs.pkgconfig
              pkgs.qt5.wrapQtAppsHook
            ];
            buildInputs = [
              pkgs.qt5.qtbase
            ];
           };
        };

        apps = rec {
          default = qrfrakt;
          qrfrakt = {
            type = "app";
            program = "${packages.rfrakt}/bin/qrfrakt";
          };
          rfrakt = {
            type = "app";
            program = "${packages.rfrakt}/bin/rfrakt";
          };
        };
      }
    );
}
