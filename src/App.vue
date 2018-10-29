<template>

  <div id="app">
    <component :is="currentView"></component>
  </div>
</template>

<script>

export default {
  name: 'App',
  data () {
    return {
      currentView: null
    }
  },
  created () {
    this.currentView = this.$router.options.routes.find(function (route) {
      var pathArray = window.location.href.split('/');
      var windowsPath = '/'+pathArray[4];
      return route.path === windowsPath;
    }).component;
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  background-color: whitesmoke;
  width:100%;
  height:100%;
  position: fixed;
}

</style>
