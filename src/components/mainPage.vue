<template>
  <div>
    <div class = "topSection" v-show="topSection">
      <div class = "nameSection">
          Joy Shalom Soosai Michael
      </div>
    </div>
    <hr v-on:click="collapseTop">
    <div class = "leftPart">
      <div class = "splitLeftBottom leftSecColor" v-show="nameImageSection" >
        <div class = "imageSection">
          <img src="../assets/selfImage.png" alt="Joy Shalom Soosai Michael">
        </div>
      </div>
      <div class = "leftCollapse">
          <a v-on:click="collapseLeft"><img style = "width:10px" src="../assets/arrowLeft.png" ></a>
      </div>
    </div>
    <div class="rightTop">
      <a class="tabStyle" v-on:click="componentChange('home')"> Home </a>
      <a class="tabStyle" v-on:click="componentChange('academic')"> Academic Experience </a>
      <a class="tabStyle" v-on:click="componentChange('professional')"> Professional Experience </a>
      <a class="tabStyle" v-on:click="componentChange('tech')"> Technical Skills </a>
      <a class="tabStyle" v-on:click="componentChange('nonTech')"> Non-Technical Skills </a>
    </div>
    <component :is="currentTab"></component>
  </div>
</template>

<script>
import Home from './HomePage'
import Academic from './AcademicPage'

export default {
  name: 'MainPage',
  methods: {
    collapseLeft () {
      this.nameImageSection = !this.nameImageSection
    },
    collapseTop () {
      this.topSection = !this.topSection
    },
    componentChange (anchorName) {
      if (anchorName === 'home') {
       this.currentTab = Home
      } else  if (anchorName === 'academic') {
        this.currentTab = Academic
      }
    }
  },
  data () {
    return {
      nameImageSection: true,
      topSection: true,
      currentTab: Home
    }
  }
}
</script>

<style scoped>
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

.topSection{
  height: 10%;
  width: 100%;
  left: 0;
  background-color:  whitesmoke;
}

.nameSection{
  color: rgb(214, 89, 16);
  font: bold;
  font-family: Georgia, 'Times New Roman', Times, serif;
  font-size: 20pt;
  padding-bottom:10px;
}

hr {
    background: url("../assets/arrowUp.png") no-repeat top center;
    background-size: contain;
    display: block;
    height: 18px;
    border: 0;
    position: relative;
}
hr:before,
hr:after {
    content: '';
    display: block;
    position: absolute;
    background: #d7d7d7;
    height: 2px;
    top: 8px;
}
hr:before {
    left: 0;
    right: 50%;
    margin-right: 10px;
}
hr:after {
    right: 0;
    left: 50%;
    margin-left: 10px;
}

.leftPart {
  left:0;
  width:22%;
}
.splitLeftBottom {
  left:0;
  width:20%;
  position: fixed;
  height: 100%;
  z-index: 1;
  overflow-x: hidden;
  border-right: 6px solid rgb(92, 4, 4);
  border-top: 6px solid rgb(92, 4, 4);
}

.leftSecColor{
  left: 0;
  background-color: #E27D60;
}

.imageSection{
  padding-top: 25px;
  border-width: 4px;
}

.leftCollapse{
  float: right;
}

.rightTop{
  width:100%;
  height:10%;
  background-color: #E27D60;
  padding-right:20px;
  float:right;
  right:-175px;
  position:relative;
}

.tabStyle{
  color: rgb(92, 4, 4);
  font: bold;
  font-family: Georgia, 'Times New Roman', Times, serif;
  font-size: 15pt;
  padding-left:3px;
  padding-top:3px;
  padding-bottom:3px;
  padding-right:15px;
  text-decoration: underline;
}
</style>
